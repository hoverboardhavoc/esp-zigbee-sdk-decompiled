/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> cvc_step_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
cvc_step_handler(uint8_t ep_id,_Bool is_on_off,ezb_zcl_level_step_cmd_payload_t *param)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  undefined3 in_register_0000202d;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  zcl_attr_desc_t *in_a5;
  zcl_attr_desc_t *unaff_s4;
  undefined1 local_40 [4];
  zcl_cvc_input_t input;
  
  if (param == (ezb_zcl_level_step_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/level.c",0x1ab,"cvc_step_handler",
                  "param");
  }
  else {
    unaff_s4 = level_srv_get_attr_desc(ep_id,0);
    pzVar2 = level_srv_get_attr_desc(ep_id,2);
    in_a5 = level_srv_get_attr_desc(ep_id,3);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uVar4 = (uint)*pzVar2->data_p;
      goto _L0;
    }
  }
  uVar4 = 0;
_L0:
  if (in_a5 == (zcl_attr_desc_t *)0x0) {
    uVar3 = 0xff;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar3 = (uint)*in_a5->data_p;
  }
                    /* WARNING: Load size is inaccurate */
  input._0_4_ = ZEXT14(*unaff_s4->data_p);
  input.end._0_2_ = 1;
  input._12_4_ = ZEXT24(param->transition_time);
  input.duration._0_1_ = 0;
  if (CONCAT31(in_register_0000202d,is_on_off) == 0) {
    pcVar5 = level_cvc_output_handler;
  }
  else {
    pcVar5 = level_cvc_with_on_off_output_handler;
  }
  input.cb = (zcl_cvc_output_callback_t)0x0;
  if (param->step_mode == '\0') {
    input.begin = (uint)param->step_size + input._0_4_;
    if ((uVar3 <= (uint)input.begin) && (input.begin = uVar3, param->step_size != 0)) {
      input._12_4_ = (input._12_4_ * (uVar3 - input._0_4_)) / (uint)param->step_size;
    }
  }
  else {
    input.begin = input._0_4_ - (uint)param->step_size;
    if ((input.begin <= (int)uVar4) && (input.begin = uVar4, param->step_size != 0)) {
      input._12_4_ = (input._12_4_ * (input._0_4_ - uVar4)) / (uint)param->step_size;
    }
  }
  local_40[0] = ep_id;
  input._20_4_ = pcVar5;
  eVar1 = schedule_cvc_level(ep_id,(zcl_cvc_input_t *)local_40);
  return eVar1;
}

