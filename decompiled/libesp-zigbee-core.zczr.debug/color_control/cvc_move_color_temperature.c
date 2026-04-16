/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_move_color_temperature
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
cvc_move_color_temperature
          (uint8_t ep_id,ezb_zcl_color_control_move_color_temperature_cmd_payload_t *payload)

{
  uint8_t uVar1;
  ezb_zcl_status_t eVar2;
  zcl_attr_desc_t *pzVar3;
  undefined1 local_30 [4];
  zcl_cvc_input_t input;
  
  if (payload == (ezb_zcl_color_control_move_color_temperature_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x60f,
                  "cvc_move_color_temperature","payload");
  }
  else {
    input.ep_id = '\0';
    input._1_3_ = 0;
    input.begin = 0;
    input.end._0_2_ = 1;
    input.quant = 0;
    input._14_2_ = 0;
    input.duration._0_1_ = 0;
    input._20_4_ = cvc_color_temperature_output_handler;
    input.cb = (zcl_cvc_output_callback_t)0x7;
    local_30[0] = ep_id;
    pzVar3 = color_control_srv_get_attr_desc(ep_id,7);
    if (pzVar3 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
                    /* WARNING: Load size is inaccurate */
    input._0_4_ = ZEXT24(*pzVar3->data_p);
    uVar1 = payload->move_mode;
    if (uVar1 != '\x01') {
      if (uVar1 != '\x03') {
        if (uVar1 == '\0') {
          stop_cvc_color(ep_id,'\x02');
          return '\0';
        }
        return 0x85;
      }
      if (payload->rate == 0) {
        return 0x85;
      }
      pzVar3 = color_control_srv_get_attr_desc(ep_id,0x400b);
      if (pzVar3 == (zcl_attr_desc_t *)0x0) {
        return 0x86;
      }
      input.begin = (int32_t)payload->color_temperature_min_mireds;
      if (input.begin == 0) {
                    /* WARNING: Load size is inaccurate */
        input.begin = (int32_t)*pzVar3->data_p;
      }
      if ((int)input._0_4_ <= input.begin) {
        return 0x87;
      }
      input._12_4_ = (int)(((uint)(ushort)input.end * 0xa0000 >> 0x10) * (input._0_4_ - input.begin)
                          ) / (int)(uint)payload->rate;
      goto _L0;
    }
  }
  if (payload->rate == 0) {
    return 0x85;
  }
  pzVar3 = color_control_srv_get_attr_desc(ep_id,0x400c);
  if (pzVar3 == (zcl_attr_desc_t *)0x0) {
    return 0x86;
  }
  input.begin = (int32_t)payload->color_temperature_max_mireds;
  if (input.begin == 0) {
                    /* WARNING: Load size is inaccurate */
    input.begin = (int32_t)*pzVar3->data_p;
  }
  if (input.begin <= (int)input._0_4_) {
    return 0x87;
  }
  input._12_4_ = (int)(((uint)(ushort)input.end * 0xa0000 >> 0x10) * (input.begin - input._0_4_)) /
                 (int)(uint)payload->rate;
_L0:
  eVar2 = schedule_cvc_color_line(ep_id,(zcl_cvc_input_t *)local_30);
  return eVar2;
}

