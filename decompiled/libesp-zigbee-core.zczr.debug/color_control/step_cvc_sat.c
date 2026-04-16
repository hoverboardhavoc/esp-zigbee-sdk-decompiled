/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> step_cvc_sat
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
step_cvc_sat(uint8_t ep_id,ezb_zcl_color_control_step_saturation_cmd_payload_t *payload)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  uint in_a5;
  undefined1 local_30 [4];
  zcl_cvc_input_t input;
  
  if (payload == (ezb_zcl_color_control_step_saturation_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x3f4,"step_cvc_sat"
                  ,"payload");
  }
  else {
    input.ep_id = '\0';
    input._1_3_ = 0;
    input.begin = 0;
    input.end._0_2_ = 1;
    input._12_4_ = ZEXT24(payload->transition_time);
    input.duration._0_1_ = 0;
    input._20_4_ = cvc_sat_output_handler;
    input.cb = (zcl_cvc_output_callback_t)0x1;
    local_30[0] = ep_id;
    pzVar2 = color_control_srv_get_attr_desc(ep_id,1);
    if (pzVar2 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
                    /* WARNING: Load size is inaccurate */
    in_a5 = (uint)*pzVar2->data_p;
    input._0_4_ = in_a5;
    if (payload->step_mode != '\x01') {
      if (payload->step_mode == '\x03') {
        input.begin = in_a5 - payload->step_size;
        if (input.begin < 0) {
          input.begin = 0;
        }
        eVar1 = '\0';
      }
      else {
        eVar1 = 0x85;
      }
      goto _L0;
    }
  }
  input.begin = in_a5 + payload->step_size;
  if (0xfe < input.begin) {
    input.begin = 0xfe;
  }
  eVar1 = '\0';
_L0:
  color_control_set_remaining_time(ep_id,payload->transition_time);
  if (eVar1 == '\0') {
    eVar1 = schedule_cvc_color_line(ep_id,(zcl_cvc_input_t *)local_30);
  }
  return eVar1;
}

