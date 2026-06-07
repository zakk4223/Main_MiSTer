#ifndef VIDEO_H
#define VIDEO_H

#define VFILTER_HORZ  0
#define VFILTER_VERT  1
#define VFILTER_SCAN  2
#define VFILTER_ILACE 3

struct VideoInfo
{
	uint32_t width;
	uint32_t height;
	uint32_t htime;
	uint32_t vtime;
	uint32_t ptime;
	uint32_t ctime;
	uint32_t vtimeh;
	uint32_t arx;
	uint32_t ary;
	uint32_t arxy;
	uint32_t fb_en;
	uint32_t fb_fmt;
	uint32_t fb_width;
	uint32_t fb_height;
	uint32_t pixrep;
	uint32_t de_h;
	uint32_t de_v;

	bool interlaced;
	bool rotated;
};

// expose video timings for timerfd-based frame timer
extern VideoInfo current_video_info;

void  video_init();
void  video_poll();

int   video_get_edid(uint8_t **buf, int *size);
void  video_hdmi_power(int on);

int   video_get_scaler_flt(int type);
void  video_set_scaler_flt(int type, int n);
char* video_get_scaler_coeff(int type, int only_name = 1);
void  video_set_scaler_coeff(int type, const char *name);

int   video_get_gamma_en();
void  video_set_gamma_en(int n);
char* video_get_gamma_curve(int only_name = 1);
void  video_set_gamma_curve(const char *name);

int   video_get_shadow_mask_mode();
void  video_set_shadow_mask_mode(int n);
char* video_get_shadow_mask(int only_name = 1);
void  video_set_shadow_mask(const char *name);
void  video_loadPreset(char *name, bool save);

int   video_get_rotated();

void video_set_vsync_adjust(int value);
void video_set_vscale_mode(int value);
void video_set_direct_video(int value);
int  video_get_vsync_adjust();
int  video_get_vscale_mode();
int  video_get_direct_video();
void video_apply_changes();
void video_revert_changes();
int video_check_revert_timer();
void video_accept_changes();
void video_start_reconfig();
int video_get_vmode();
void video_get_vmode_description(int vmode, char *res, size_t res_size);
void video_set_vmode(int value);


void video_cfg_reset();

void  video_mode_adjust(bool force = false);

int   hasAPI1_5();

void video_fb_enable(int enable, int n = 0);
int video_fb_state();
void video_menu_bg(int n, int idle = 0);
int video_bg_has_picture();
int video_chvt(int num);
void video_cmd(char *cmd);
void video_mode_cmd(char *cmd);

void video_core_description(char *str, size_t len);
void video_scaler_description(char *str, size_t len);
char* video_get_core_mode_name(int with_vrefresh = 1);

void dbg_draw_cursor(int x, int y);

#endif // VIDEO_H
