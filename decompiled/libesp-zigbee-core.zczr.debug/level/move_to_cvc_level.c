/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> move_to_cvc_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
move_to_cvc_level(uint8_t ep_id,_Bool is_on_off,ezb_zcl_level_move_to_level_cmd_payload_t *payload)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  undefined3 in_register_0000202d;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  undefined1 local_30 [4];
  zcl_cvc_input_t input;
  
  if (payload == (ezb_zcl_level_move_to_level_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/level.c",0x12a,"move_to_cvc_level",
                  "payload");
  }
  else {
    local_30[0] = ep_id;
    pzVar2 = level_srv_get_attr_desc(ep_id,0);
                    /* WARNING: Load size is inaccurate */
    input._0_4_ = ZEXT14(*pzVar2->data_p);
    input.begin = (int32_t)payload->level;
    input.end._0_2_ = 1;
    input._12_4_ = ZEXT24(payload->transition_time);
    input.duration._0_1_ = 0;
    if (CONCAT31(in_register_0000202d,is_on_off) != 0) {
      pcVar6 = level_cvc_with_on_off_output_handler;
      goto _L0;
    }
  }
  pcVar6 = level_cvc_output_handler;
_L0:
  input.cb = (zcl_cvc_output_callback_t)0x0;
  input._20_4_ = pcVar6;
  pzVar2 = level_srv_get_attr_desc(ep_id,2);
  pzVar3 = level_srv_get_attr_desc(ep_id,3);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    uVar5 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar5 = (uint)*pzVar2->data_p;
  }
  if (pzVar3 == (zcl_attr_desc_t *)0x0) {
    uVar4 = 0xff;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar4 = (uint)*pzVar3->data_p;
  }
  input.begin = (int32_t)payload->level;
  if ((int)input._0_4_ < input.begin) {
    if (uVar4 < (uint)input.begin) {
      input.begin = uVar4;
    }
  }
  else if ((uint)input.begin < uVar5) {
    input.begin = uVar5;
  }
  uVar5 = (uint)payload->transition_time;
  if (payload->transition_time == 0xffff) {
    pzVar2 = level_srv_get_attr_desc(ep_id,0x10);
    if (pzVar2 == (zcl_attr_desc_t *)0x0) {
      input.quant = 0xffff;
      input._14_2_ = 0;
      uVar5 = input._12_4_;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar5 = (uint)*pzVar2->data_p;
    }
  }
  input._12_4_ = uVar5;
  eVar1 = schedule_cvc_level(ep_id,(zcl_cvc_input_t *)local_30);
  return eVar1;
}

