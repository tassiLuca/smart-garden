const URL_REQUEST = "http://localhost:8080/api/data";

var label = 0;
var lightness = [];
var temperature = [];

$(document).ready(function() {

    setInterval(getData, 1000);

});


function getData() {
    $.get(URL_REQUEST, function(data){
        for (i = 0; i < data.data.length; i++) {
            lightness.push(data.data[i].lightness);
            temperature.push(data.data[i].temperature);
        }
    })
    addData(lightness, temperature);
    lightness = []
    temperature = []
}


const canvas = document.getElementById("chart");
const data = {
    labels: [],
    datasets: [{
        label: "My First dataset",
        fill: false,
        lineTension: 0.0,
        backgroundColor: "rgba(75,192,192,0.4)",
        borderColor: "rgba(75,192,192,1)",
        borderCapStyle: 'butt',
        borderDash: [],
        borderDashOffset: 0.0,
        borderJoinStyle: 'miter',
        pointBorderColor: "rgba(75,192,192,1)",
        pointBackgroundColor: "#fff",
        pointBorderWidth: 1,
        pointHoverRadius: 5,
        pointHoverBackgroundColor: "rgba(75,192,192,1)",
        pointHoverBorderColor: "rgba(220,220,220,1)",
        pointHoverBorderWidth: 2,
        pointRadius: 5,
        pointHitRadius: 10,
        data: [],
    }, {
        label: "My second dataset",
        fill: false,
        lineTension: 0.0,
        backgroundColor: "rgba(192,192,192,0.4)",
        borderColor: "rgba(75,192,192,1)",
        borderCapStyle: 'butt',
        borderDash: [],
        borderDashOffset: 0.0,
        borderJoinStyle: 'miter',
        pointBorderColor: "rgba(75,192,192,1)",
        pointBackgroundColor: "#fff",
        pointBorderWidth: 1,
        pointHoverRadius: 5,
        pointHoverBackgroundColor: "rgba(75,192,192,1)",
        pointHoverBorderColor: "rgba(220,220,220,1)",
        pointHoverBorderWidth: 2,
        pointRadius: 5,
        pointHitRadius: 10,
        data: [],
    }]
};
const option = {
    showLines: true,
    scales: {
        yAxes: [{
            display: true,
            ticks: {
                beginAtZero: true,
                min: 0,
                max: 9
            }
        }]
    }
};

const chart = Chart.Line(canvas, {
    data: data,
    options: option
});

function addData(lightness, temperature) {
    console.log(temperature);
    console.log(lightness);
    chart.data.labels.splice(0, lightness.length);
    for (let i = 0; i < lightness.length; i++) {
        chart.data.labels.push(label++);
    }
    chart.data.datasets[0].data.splice(0, lightness.length);
    chart.data.datasets[1].data.splice(0, temperature.length);
    for (let i = 0; i < lightness.length; i++) {
        chart.data.datasets[0].data.push(lightness[i]);
        chart.data.datasets[1].data.push(temperature[i]);
    }
    chart.update();
    // var value = Math.floor((Math.random() * 100) + 1);
    // chart.data.labels.push(label);
    // chart.data.labels.splice(0, 1);
    // chart.data.datasets[0].data.splice(0, 1);
    // chart.data.datasets[1].data.splice(0, 1);
    // chart.data.datasets[0].data.push(value);
    // chart.data.datasets[1].data.push(value+6);
    // chart.update();
    // zero++;
}
