const URL_REQUEST = "http://localhost:8080/api/data";

var labels = [];
var lightness = [];
var temperature = [];

$(document).ready(function() {
    setInterval(getData, 1000);
});

function getData() {
    $.get(URL_REQUEST, function(data){
        $("#state").html(data.status);
        for (i = 0; i < data.data.length; i++) {
            labels.push(data.data[i].timestamp);
            lightness.push(data.data[i].lightness);
            temperature.push(data.data[i].temperature);
        }
    })
    addData(lightness, temperature);
    lightness = [];
    temperature = [];
    labels = [];
}

function addData(lightness, temperature) {
    chart.data.labels.splice(0, labels.length);
    for (let i = 0; i < lightness.length; i++) {
        chart.data.labels.push(labels[i]);
    }
    chart.data.datasets[0].data.splice(0, lightness.length);
    chart.data.datasets[1].data.splice(0, temperature.length);
    for (let i = 0; i < lightness.length; i++) {
        chart.data.datasets[0].data.push(lightness[i]);
        chart.data.datasets[1].data.push(temperature[i]);
    }
    chart.update();
}

const canvas = document.getElementById("chart");
const data = {
    labels: [],
    datasets: [{
        label: "Lightness",
        fill: false,
        lineTension: 0.3,
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
        label: "Temperature",
        fill: false,
        lineTension: 0.3,
        backgroundColor: "rgba(251, 157, 36, 0.4)",
        borderColor: "rgba(251, 157, 36, 1)",
        borderCapStyle: 'butt',
        borderDash: [],
        borderDashOffset: 0.0,
        borderJoinStyle: 'miter',
        pointBorderColor: "rgba(251, 157, 36, 1)",
        pointBackgroundColor: "#fff",
        pointBorderWidth: 1,
        pointHoverRadius: 5,
        pointHoverBackgroundColor: "rgba(251, 157, 36, 1)",
        pointHoverBorderColor: "rgba(220,220,220,1)",
        pointHoverBorderWidth: 2,
        pointRadius: 5,
        pointHitRadius: 10,
        data: [],
    }]
};
const option = {
    showLines: true,
    responsive: true,
    scales: {
        xAxes: [{
            ticks: {
                maxRotation: 90,
                minRotation: 90
            }
        }],
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
