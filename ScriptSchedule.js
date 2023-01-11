/**
 * 1. Open the appointment reschedule page
 * 2. Open Google Chrome console (ctrl + shift + i, then click on the 'console' tab)
 * 3. Copy, paste and run this code
 * 4. A box with options and a strat button should appear on the right top
 *   corner of the screen
 * */
(async () => {
    let dateBefore = '2023-01-01';
    const intervalCheck = 10000;
    let running = false;
    
    $(`
        <div id="check-dates">
        <select id="check-dates-city">
            <option value="54">Brasilia</option>
            <option value="128">Porto Alegre</option>
            <option value="57">Recife</option>
            <option value="55">Rio de Janeiro</option>
            <option value="56" selected>Sao Paulo</option>
        </select>
        <label>check for dates before: </label>
        <input type="text" id="check-dates-date" placeholder="${dateBefore}"></input>
        <div id="check-dates-counter"></div>
        <span id="check-dates-last-date"></span>
        <button id="check-dates-start">start</button>
        </div>`).appendTo('body');
    $(`
        <style>
          #check-dates {
            position: fixed;
            top: 0;
            right: 0;
            width: 200px;
            background: white;
            z-index: 100;
            padding: 10px;
            border: 1px solid red;
          }
          #check-dates.running {
            border: 1px solid green;
          }
          #check-dates-start {
            display: block;
            cursor: pointer;
            background-color: #91f086;
            padding: 10px 20px;
          }
          .running #check-dates-start {
            background-color: #ffbaba;
          }
          #check-dates-last-date {
            display: block;
            margin: 10px 0;
          }
        </style>`
    ).appendTo('head');
 
    $('#check-dates-date').keyup((e) => {
        dateBefore = $(e.currentTarget).val()
    })
    
    if (("Notification" in window) && Notification.permission !== 'granted') {
        Notification.requestPermission((permission) => { Notification.permission = permission });
    }
 
    const notifyMe = (text) => {
      if (!("Notification" in window)) return
      if (Notification.permission === "granted") {
          new Notification(text);
      }
    }
 
    const getDates = async (n) => {
        const response = await fetch(window.location.href+"/days/"+$('#check-dates-city').val()+".json?appointments[expedite]=false", {
        "headers": {
            "accept": "application/json, text/javascript, /; q=0.01",
            "accept-language": "en-US,en;q=0.9",
            "x-csrf-token": $('meta[name=csrf-token]').attr('content'),
            "x-requested-with": "XMLHttpRequest"
        },
        "referrerPolicy": "strict-origin-when-cross-origin",
        "body": null,
        "method": "GET",
        "mode": "cors",
        "credentials": "include"
        });
 
        return (await response.json()).slice(0, n);
    }
 
    $('#check-dates-start').on('click', () => {
        if (running) return
        $('#check-dates-date').prop('disabled', true)
        $('#check-dates-start').text('stop');
        $('#check-dates').addClass('running');
        running = true;
        
        let seconds = intervalCheck / 1000;
        const counter = setInterval(() => {
            $('#check-dates-counter').text('updating in ' + seconds + 's');
            seconds--;
            if (seconds == 0) {
                seconds = intervalCheck / 1000;
            }
        }, 1000)
        const myInterval = setInterval(async () => {
            const el = (await getDates(5))[0]
            $('#check-dates-last-date').text('Last check available date: ' + el.date)
            console.log(dateBefore);
            if (new Date(el.date) < new Date(dateBefore)) {
                const music = new Audio('https://audio-previews.elements.envatousercontent.com/files/173153038/preview.mp3?response-content-disposition=attachment%3B+filename%3D%22NBUK26X-alarm.mp3%22');
                music.play();
                notifyMe('new good date ' + el.date);
                $('#check-dates-start').trigger('click');
            }
        }, intervalCheck)
        
        $('#check-dates-start').one('click', () => {
            running = false;
            clearInterval(myInterval);
            clearInterval(counter);
            $('#check-dates-counter').text('');
            $('#check-dates-date').prop('disabled', false);
            $('#check-dates').removeClass('running');
            $('#check-dates-start').text('start');
        })
    })
})()