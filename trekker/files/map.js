ymaps.ready(init);

function init() {
    // Создаем карту.
    var myMap = new ymaps.Map("map", {
            center: [55.72, 37.44],
            zoom: 15
        });


    // Создаем ломаную с помощью вспомогательного класса Polyline.
    var myPath = new ymaps.Polyline([
            // Указываем координаты вершин ломаной.
            [55.80, 37.50],
            [55.90, 37.30],
            [55.60, 37.20],
            [55.80, 37.10]
        ], {
            // Описываем свойства геообъекта.
            // Содержимое балуна.
            balloonContent: "Траектория маршрута"
        }, {
            // Задаем опции геообъекта.
            // Отключаем кнопку закрытия балуна.
            balloonCloseButton: false,
            // Цвет линии.
            strokeColor: "#000000",
            // Ширина линии.
            strokeWidth: 2,
            // Коэффициент прозрачности.
            strokeOpacity: 1
        });
    
    
            // Создаем метку с помощью вспомогательного класса.
        myPlace = new ymaps.Placemark([55.80, 37.50], {
            // Свойства.
            // Содержимое иконки, балуна и хинта.
            iconContent: '1',
            balloonContent: 'Точка местоположения',
            hintContent: 'Метка'
        }, {
            // Опции.
            // Стандартная фиолетовая иконка.
            preset: 'twirl#violetIcon'
        });

    // Добавляем линии на карту.
    myMap.geoObjects.add(myPath);
	
    myMap.geoObjects.add(myPlace)
	
    myMap.controls.add('scaleLine');
    myMap.controls.add('zoomControl');
    myMap.controls.add('typeSelector');
}
