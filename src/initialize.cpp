#include "main.h"
#include "globals.hpp"

lv_obj_t * allianceButton;
lv_obj_t * allianceButtonLabel;
lv_obj_t * positionButton;
lv_obj_t * positionButtonLabel;

lv_style_t blueAllianceStyle; //relesed style
lv_style_t redAllianceStyle; //pressed style

static lv_res_t allianceButtonAction(lv_obj_t * btn)
{
    if (alliance == false) {
        alliance = true;
        lv_label_set_text(allianceButtonLabel, "Red Alliance");
    }
    else if (alliance == true) {
        alliance = false;
        lv_label_set_text(allianceButtonLabel, "Blue Alliance");
    }

    return LV_RES_OK;
}

static lv_res_t positionButtonAction(lv_obj_t * btn)
{
    if (position == 0) {
        position = 1;
        lv_label_set_text(positionButtonLabel, "Right Position");
    }
    else if (position == 1) {
        position = 0;
        lv_label_set_text(positionButtonLabel, "Left Position");
    }

    return LV_RES_OK;
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    alliance = false; // false red, true blue
    position = 0; //0 left, 1 right

	lv_style_copy(&blueAllianceStyle, &lv_style_plain);
	blueAllianceStyle.body.main_color = LV_COLOR_MAKE(0, 0, 255);
	blueAllianceStyle.body.grad_color = LV_COLOR_MAKE(255, 255, 255);
	blueAllianceStyle.body.radius = 0;
	blueAllianceStyle.text.color = LV_COLOR_MAKE(0,0,0);

	lv_style_copy(&redAllianceStyle, &lv_style_plain);
	redAllianceStyle.body.main_color = LV_COLOR_MAKE(255, 0, 0);
	redAllianceStyle.body.grad_color = LV_COLOR_MAKE(255, 255, 255);
	redAllianceStyle.body.radius = 0;
	redAllianceStyle.text.color = LV_COLOR_MAKE(0,0,0);

	allianceButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
	lv_obj_set_free_num(allianceButton, 0); //set button is to 0
	lv_btn_set_action(allianceButton, LV_BTN_ACTION_CLICK, allianceButtonAction); //set function to be called on button click
	lv_btn_set_style(allianceButton, LV_BTN_STYLE_TGL_REL, &blueAllianceStyle); //set the relesed style
	lv_btn_set_style(allianceButton, LV_BTN_STYLE_TGL_PR, &redAllianceStyle); //set the pressed style
	lv_obj_set_size(allianceButton, 200, 50); //set the button size
	lv_obj_align(allianceButton, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10); //set the position to top mid
    lv_btn_set_state(allianceButton, LV_BTN_STATE_TGL_REL);

    positionButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
	lv_obj_set_free_num(positionButton, 0); //set button is to 0
	lv_btn_set_action(positionButton, LV_BTN_ACTION_CLICK, positionButtonAction); //set function to be called on button click

    positionButtonLabel = lv_label_create(positionButton, NULL);
    lv_label_set_text(positionButtonLabel, "Left Position");

	allianceButtonLabel = lv_label_create(allianceButton, NULL); //create label and puts it inside of the button
	lv_label_set_text(allianceButtonLabel, "Blue Alliance"); //sets label text
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
