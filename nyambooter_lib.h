/*Библиотека стандартных функций
Координаты на экране:
(x = 0, y = 0) - верхняя левая точка экрана
Увеличение x сдвигает координату вправо на экране
Увеличение y сдвигает координату вниз на экране
*/

//=========================================================================
//Работа с цветом
//Структура цвета 24 бит
typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} nb_rgb_t;

/*Смешивает два цвета. Чем больше alpha, тем выходной цвет ближе к color2*/
nb_rgb_t nb_graphic_blend_color_24b(nb_rgb_t color1, nb_rgb_t color2, uint8_t alpha);

/*Объединяет байты цвета в структуру*/
nb_rgb_t nb_graphic_bytes_to_rgb(uint8_t red, uint8_t green, uint8_t blue);

/*Объединяет байты цвета в 32 битное число (без альфа). Красный цвет помещается в биты 16...23, зелёный в биты 8..15, синий в биты 0..7*/
uint32_t nb_graphic_bytes_to_color_24b(uint8_t red, uint8_t green, uint8_t blue);

/*Конвертация байт 24 битного цвета в 16 битный R5G6B5 (красный в старших разрядах)*/
uint16_t nb_graphic_convert_color_24b_to_16b(uint8_t red,uint8_t green,uint8_t blue);

//=========================================================================
//Графические функции для работы с дисплеем

/*Выводит графический буфер в дисплей для отображения*/
void nb_graphic_update(void);

/*Возвращает ширину дисплея устройства*/
int32_t nb_graphic_get_screen_width(void);

/*Возвращает высоту дисплея устройства*/
int32_t nb_graphic_get_screen_height(void);

/*Устанавливает область рисования для всех графических функций.
Все пиксели вне этой области рисоваться не будут.
Можно это использовать для рисования обрезанных фигур или изображений.*/
void nb_graphic_set_draw_area(int32_t left, int32_t top, int32_t right, int32_t bottom);

/*Устанавливает область рисования для всех графических функций, равную ширине и высоте дисплея*/
void nb_graphic_set_draw_area_to_max(void);

/*Возвращает 1, если координаты (x,y) находятся в текущей области рисования,
заданной функцией nb_graphic_set_draw_area().
Если (left <= x <= right) и (top <= y <= bottom), то возвращается 1.*/
uint8_t nb_graphic_check_in_area(int32_t x, int32_t y);

/*Устанавливает глобальный цвет рисования для графических функций без параметра color*/
void nb_graphic_set_color_16b(uint16_t color);

/*Выдаёт в буфере глобальный цвет рисования*/
uint16_t nb_graphic_get_color_16b(void);

/*Рисует в графическом буфере пиксель с цветом 16 бит R5G6B5*/
void nb_graphic_draw_pixel_16b(int32_t x, int32_t y, uint16_t color);

/*Рисует в графическом буфере пиксель глобальным цветом*/
void nb_graphic_draw_pixel(int32_t x, int32_t y);

/*Закрашивает весь графический буфер одним цветом 16 бит R5G6B5 (даже вне области рисования)*/
void nb_graphic_fill_all_16b(uint16_t color);

/*Закрашивает одним цветом 16 бит R5G6B5 только область рисования в графическом буфере*/
void nb_graphic_fill_area_16b(uint16_t color);

/*Рисует в буфере линию по двум точкам глобальным цветом*/
void nb_graphic_draw_line(int32_t x1,int32_t y1, int32_t x2, int32_t y2);

/*Рисует в буфере прямоугольник по точкам глобальным цветом*/
void nb_graphic_draw_rectangle_xy(int32_t x1, int32_t y1, int32_t x2, int32_t y2);

/*Рисует в буфере закрашенный прямоугольник по точкам глобальным цветом*/
void nb_graphic_draw_fill_rectangle_xy(int32_t x1, int32_t y1, int32_t x2, int32_t y2);

/*Рисует в буфере прямоугольник по точке, ширине и высоте глобальным цветом*/
void nb_graphic_draw_rectangle_wh(int32_t x, int32_t y, int32_t width, int32_t height);

/*Рисует в буфере закрашенный прямоугольник по точке, ширине и высоте глобальным цветом*/
void nb_graphic_draw_fill_rectangle_wh(int32_t x, int32_t y, int32_t width, int32_t height);

/*Рисует в буфере окружность глобальным цветом*/
void nb_graphic_draw_circle(int32_t x, int32_t y, int32_t radius);

/*Рисует в буфере круг глобальным цветом*/
void nb_graphic_draw_fill_circle(int32_t x, int32_t y, int32_t radius);
//=========================================================================
//Системные функции

/*Возвращает количество миллисекунд, прошедшее от запуска программы*/
uint32_t nb_sys_get_counter_ms(void);

/*Задержка выполнения на указанное время в миллисикундах*/
void nb_sys_loop_delay_ms(uint32_t ms);

//Названия кнопок (Right, Left, Up, Down) и соответствующие им биты
#define		NB_KEY_R		(0x0001)
#define		NB_KEY_L		(0x0002)
#define		NB_KEY_U		(0x0004)
#define		NB_KEY_D		(0x0008)
#define		NB_KEY_A		(0x0010)
#define		NB_KEY_B		(0x0020)
#define		NB_KEY_X		(0x0040)
#define		NB_KEY_Y		(0x0080)
#define		NB_KEY_MENU		(0x0100)

/*Выдаёт биты состояния кнопок (=0 нажата, =1 отжата)*/
uint32_t nb_sys_get_keys_state(void);

/*Возвращает случайное 32-битное число*/
uint32_t nb_sys_get_random_u32(void);
//=========================================================================
