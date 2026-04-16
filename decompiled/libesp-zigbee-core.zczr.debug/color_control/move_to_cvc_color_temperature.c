/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> move_to_cvc_color_temperature
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
move_to_cvc_color_temperature
          (uint8_t ep_id,ezb_zcl_color_control_move_to_color_temperature_cmd_payload_t *payload)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  zcl_attr_desc_t *pzVar3;
  undefined3 extraout_var;
  uint16_t uStack_34;
  uint16_t uStack_32;
  uint16_t max_temperature;
  uint16_t min_temperature;
  zcl_cvc_input_t input;
  
  if (payload == (ezb_zcl_color_control_move_to_color_temperature_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x5d2,
                  "move_to_cvc_color_temperature","payload");
  }
  else {
    input.ep_id = '\0';
    input._1_3_ = 0;
    input.begin = 0;
    input.duration = 0;
    _max_temperature = (uint)ep_id;
    input.end = 1;
    input._12_4_ = ZEXT24(payload->transition_time);
    input._20_4_ = cvc_color_temperature_output_handler;
    input.cb = (zcl_cvc_output_callback_t)0x7;
    uStack_32 = 0;
    uStack_34 = 0;
    pzVar3 = color_control_srv_get_attr_desc(ep_id,7);
    if (pzVar3 != (zcl_attr_desc_t *)0x0) {
      _Var1 = color_control_get_color_temperature_range(ep_id,&uStack_32,&uStack_34);
      if (CONCAT31(extraout_var,_Var1) != 0) {
                    /* WARNING: Load size is inaccurate */
        input._0_4_ = ZEXT24(*pzVar3->data_p);
        input.begin = (uint)uStack_32;
        if ((uint)uStack_32 < (uint)payload->color_temperature_mireds) {
          input.begin = (uint)payload->color_temperature_mireds;
        }
        if ((uint)uStack_34 < (uint)input.begin) {
          input.begin = (uint)uStack_34;
        }
        eVar2 = schedule_cvc_color_line(ep_id,(zcl_cvc_input_t *)&max_temperature);
        return eVar2;
      }
      return 0x86;
    }
  }
  return 0x86;
}

