#include "test.h"

/*void drawRandomRect (VkvgContext ctx) {
	float w = (float)test_width;
	float h = (float)test_height;
	randomize_color(ctx);

	float z = truncf((0.5f*w*rand()/RAND_MAX)+1.f);
	float v = truncf((0.5f*w*rand()/RAND_MAX)+1.f);
	float x = truncf((w-z)*rand()/RAND_MAX);
	float y = truncf((h-v)*rand()/RAND_MAX);

	vkvg_rectangle(ctx, x, y, z, v);
}*/
static vkvg_fill_rule_t fill_rule = VKVG_FILL_RULE_EVEN_ODD;
static vkvg_line_cap_t line_cap = VKVG_LINE_CAP_BUTT;
static vkvg_line_join_t line_join = VKVG_LINE_JOIN_MITER;
static float line_width = 1.f;
static float shape_size = 0.2f;
static float dashes[] = {3.0f, 10.0f};
static uint32_t dashes_count = 0;


void _shape_fill(shape_t shape){
	VkvgContext ctx = vkvg_create(surf);
	vkvg_clear(ctx);
	vkvg_set_fill_rule(ctx, fill_rule);
	for (uint32_t i=0; i<test_size; i++) {
		draw_random_shape(ctx, shape, shape_size);
		vkvg_fill(ctx);
	}
	vkvg_destroy(ctx);
}
void _shape_stroke(shape_t shape){
	VkvgContext ctx = vkvg_create(surf);
	vkvg_clear(ctx);
	vkvg_set_line_width (ctx, line_width);
	vkvg_set_line_cap(ctx, line_cap);
	vkvg_set_line_join (ctx, line_join);
	vkvg_set_dash (ctx, dashes, dashes_count, 0);
	vkvg_set_fill_rule(ctx, fill_rule);
	for (uint32_t i=0; i<test_size; i++) {
		draw_random_shape(ctx, shape, shape_size);
		vkvg_stroke (ctx);
	}
	vkvg_destroy(ctx);
}
void _shape_fill_stroke(shape_t shape){
	VkvgContext ctx = vkvg_create(surf);
	vkvg_clear(ctx);
	vkvg_set_line_width (ctx, line_width);
	vkvg_set_line_cap(ctx, line_cap);
	vkvg_set_line_join (ctx, line_join);

	vkvg_set_dash (ctx, dashes, dashes_count, 0);
	vkvg_set_fill_rule(ctx, fill_rule);
	for (uint32_t i=0; i<test_size; i++) {
		draw_random_shape(ctx, shape, shape_size);
		vkvg_fill_preserve(ctx);
		vkvg_stroke(ctx);
	}
	vkvg_destroy(ctx);
}

void rectangles_fill () {
	_shape_fill(SHAPE_RECTANGLE);
}
void rectangles_stroke () {
	_shape_stroke(SHAPE_RECTANGLE);
}
void rectangles_fill_stroke () {
	_shape_fill_stroke(SHAPE_RECTANGLE);
}
void rounded_rects_fill () {
	_shape_fill(SHAPE_ROUNDED_RECTANGLE);
}
void rounded_rects_stroke () {
	_shape_stroke(SHAPE_ROUNDED_RECTANGLE);
}
void rounded_rects_fill_stroke () {
	_shape_fill_stroke(SHAPE_ROUNDED_RECTANGLE);
}
void circles_fill () {
	_shape_fill(SHAPE_CIRCLE);
}
void circles_stroke () {
	_shape_stroke(SHAPE_CIRCLE);
}
void circles_fill_stroke () {
	_shape_fill_stroke(SHAPE_CIRCLE);
}
void stars_fill () {
	_shape_fill(SHAPE_STAR);
}
void stars_stroke () {
	_shape_stroke(SHAPE_STAR);
}
void stars_fill_stroke () {
	_shape_fill_stroke(SHAPE_STAR);
}
void random_fill () {
	_shape_fill(SHAPE_RANDOM);
}
void random_stroke () {
	_shape_stroke(SHAPE_RANDOM);
}
void random_fill_stroke () {
	_shape_fill_stroke(SHAPE_RANDOM);
}

int main(int argc, char *argv[]) {
	srand(0);

	PERFORM_TEST (rectangles_fill, argc, argv);
	PERFORM_TEST (rectangles_stroke, argc, argv);
	PERFORM_TEST (rectangles_fill_stroke, argc, argv);

	PERFORM_TEST (rounded_rects_fill, argc, argv);
	PERFORM_TEST (rounded_rects_stroke, argc, argv);
	PERFORM_TEST (rounded_rects_fill_stroke, argc, argv);

	PERFORM_TEST (circles_fill, argc, argv);
	PERFORM_TEST (circles_stroke, argc, argv);
	PERFORM_TEST (circles_fill_stroke, argc, argv);

	PERFORM_TEST (stars_fill, argc, argv);
	PERFORM_TEST (stars_stroke, argc, argv);
	PERFORM_TEST (stars_fill_stroke, argc, argv);

	PERFORM_TEST (random_fill, argc, argv);
	PERFORM_TEST (random_stroke, argc, argv);
	PERFORM_TEST (random_fill_stroke, argc, argv);

	return 0;
}
