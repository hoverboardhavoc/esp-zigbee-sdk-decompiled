/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_move_to_color_xy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: x_input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
cvc_move_to_color_xy(uint8_t ep_id,ezb_zcl_color_control_move_to_color_cmd_payload_t *payload)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  undefined1 local_50 [4];
  zcl_cvc_input_t y_input;
  zcl_cvc_input_t x_input;
  
  if (payload == (ezb_zcl_color_control_move_to_color_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x4d1,
                  "cvc_move_to_color_xy","payload");
  }
  else {
    y_input.data = (uintptr_t)ep_id;
    y_input._12_4_ = ZEXT24(payload->transition_time);
    y_input.ep_id = '\0';
    y_input._1_3_ = 0;
    y_input.begin = 0;
    y_input.duration = 0;
    local_50._1_3_ = 0;
    local_50[0] = ep_id;
    y_input.end = 1;
    y_input._20_4_ = cvc_color_xy_output_handler;
    y_input.cb = (zcl_cvc_output_callback_t)0x4;
    if (payload->color_x < 0xff00) {
      if (0xfeff < payload->color_y) {
        return 0x87;
      }
      pzVar2 = color_control_srv_get_attr_desc(ep_id,3);
      pzVar3 = color_control_srv_get_attr_desc(ep_id,4);
      if (pzVar2 != (zcl_attr_desc_t *)0x0) {
        if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
          y_input._0_4_ = ZEXT24(*pzVar3->data_p);
          y_input.begin = (int32_t)payload->color_y;
          eVar1 = schedule_cvc_color_space
                            (ep_id,(zcl_cvc_input_t *)&y_input.data,(zcl_cvc_input_t *)local_50);
          return eVar1;
        }
        return 0x86;
      }
      return 0x86;
    }
  }
  return 0x87;
}

