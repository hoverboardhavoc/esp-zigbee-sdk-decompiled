/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_move_hue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t cvc_move_hue(uint8_t ep_id,ezb_zcl_color_control_move_hue_cmd_payload_t *payload)

{
  uint8_t uVar1;
  ezb_zcl_status_t eVar2;
  zcl_attr_desc_t *pzVar3;
  uint in_a5;
  undefined1 local_30 [4];
  zcl_cvc_input_t input;
  
  if (payload == (ezb_zcl_color_control_move_hue_cmd_payload_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x33b
                  ,"cvc_move_hue","payload");
  }
  else {
    input.ep_id = '\0';
    input._1_3_ = 0;
    input.begin = 0;
    input.end._0_2_ = 1;
    input.quant = 10;
    input._14_2_ = 0;
    input.duration._0_1_ = 1;
    input._20_4_ = cvc_hue_output_handler;
    input.cb = (zcl_cvc_output_callback_t)0x0;
    local_30[0] = ep_id;
    pzVar3 = color_control_srv_get_attr_desc(ep_id,0);
    if (pzVar3 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
                    /* WARNING: Load size is inaccurate */
    in_a5 = (uint)*pzVar3->data_p;
    uVar1 = payload->move_mode;
    input._0_4_ = in_a5;
    if (uVar1 != '\x01') {
      if (uVar1 != '\x03') {
        if (uVar1 == '\0') {
          stop_cvc_color(ep_id,'\0');
          return '\0';
        }
        return 0x85;
      }
      if (payload->rate == 0) {
        return 0x85;
      }
      input.begin = in_a5 - payload->rate;
      goto _L0;
    }
  }
  if (payload->rate == 0) {
    return 0x85;
  }
  input.begin = in_a5 + payload->rate;
_L0:
  eVar2 = schedule_cvc_color_line(ep_id,(zcl_cvc_input_t *)local_30);
  return eVar2;
}

