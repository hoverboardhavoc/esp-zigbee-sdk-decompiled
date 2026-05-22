/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_enhanced_move_to_hue_and_sat
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: hue_input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
cvc_enhanced_move_to_hue_and_sat
          (uint8_t ep_id,
          ezb_zcl_color_control_enhanced_move_to_hue_and_saturation_cmd_payload_t *payload)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  undefined1 local_50 [4];
  zcl_cvc_input_t sat_input;
  zcl_cvc_input_t hue_input;
  
  if (payload == (ezb_zcl_color_control_enhanced_move_to_hue_and_saturation_cmd_payload_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x7cc
                  ,"cvc_enhanced_move_to_hue_and_sat","payload");
  }
  else {
    sat_input.data = (uintptr_t)ep_id;
    sat_input._12_4_ = ZEXT24(payload->transition_time);
    sat_input.ep_id = '\0';
    sat_input._1_3_ = 0;
    sat_input.begin = 0;
    sat_input.duration = 0;
    local_50._1_3_ = 0;
    local_50[0] = ep_id;
    sat_input.end = 1;
    sat_input._20_4_ = cvc_sat_output_handler;
    sat_input.cb = (zcl_cvc_output_callback_t)0x1;
    if (payload->saturation != 0xff) {
      pzVar2 = color_control_srv_get_attr_desc(ep_id,0x4000);
      pzVar3 = color_control_srv_get_attr_desc(ep_id,1);
      if (pzVar2 == (zcl_attr_desc_t *)0x0) {
        return 0x86;
      }
      if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        sat_input._0_4_ = ZEXT14(*pzVar3->data_p);
        sat_input.begin = (int32_t)payload->saturation;
        eVar1 = schedule_cvc_color_space
                          (ep_id,(zcl_cvc_input_t *)&sat_input.data,(zcl_cvc_input_t *)local_50);
        return eVar1;
      }
      return 0x86;
    }
  }
  return 0x87;
}

