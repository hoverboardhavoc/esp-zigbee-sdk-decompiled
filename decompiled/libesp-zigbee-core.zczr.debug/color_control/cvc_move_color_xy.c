/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_move_color_xy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: x_input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
cvc_move_color_xy(uint8_t ep_id,ezb_zcl_color_control_move_color_cmd_payload_t *payload)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  uint8_t in_a4;
  undefined1 local_50 [4];
  zcl_cvc_input_t y_input;
  zcl_cvc_input_t x_input;
  
  if (payload == (ezb_zcl_color_control_move_color_cmd_payload_t *)0x0) {
    ep_id = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c"
                          ,0x518,"cvc_move_color_xy","payload");
  }
  else {
    in_a4 = '\x01';
    y_input.ep_id = '\0';
    y_input._1_3_ = 0;
    y_input.begin = 0;
    y_input.end._0_2_ = 1;
    y_input.quant = 0;
    y_input._14_2_ = 0;
    y_input.duration._0_1_ = 1;
    y_input._20_4_ = cvc_color_xy_output_handler;
    y_input.cb = (zcl_cvc_output_callback_t)0x4;
    local_50[0] = ep_id;
    y_input.data._0_1_ = ep_id;
    if ((payload->rate_x != 0) || (payload->rate_y != 0)) {
      pzVar2 = color_control_srv_get_attr_desc(ep_id,3);
      pzVar3 = color_control_srv_get_attr_desc(ep_id,4);
      if (pzVar2 == (zcl_attr_desc_t *)0x0) {
        return 0x86;
      }
      if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        y_input._0_4_ = ZEXT24(*pzVar3->data_p);
        y_input.begin = y_input._0_4_ + (uint)payload->rate_y;
        if (payload->rate_y == 0) {
          y_input.quant = 0;
          y_input._14_2_ = 0;
        }
        else {
          y_input.quant = 10;
          y_input._14_2_ = 0;
        }
        eVar1 = schedule_cvc_color_space
                          (ep_id,(zcl_cvc_input_t *)&y_input.data,(zcl_cvc_input_t *)local_50);
        return eVar1;
      }
      return 0x86;
    }
  }
  stop_cvc_color(ep_id,in_a4);
  return 0xfe;
}

