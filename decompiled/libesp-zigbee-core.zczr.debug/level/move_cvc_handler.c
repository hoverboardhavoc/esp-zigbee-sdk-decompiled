/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> move_cvc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
move_cvc_handler(uint8_t ep_id,_Bool is_on_off,ezb_zcl_level_move_cmd_payload_t *param)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  undefined3 in_register_0000202d;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  zcl_attr_desc_t *unaff_s3;
  uint uVar6;
  zcl_attr_desc_t *unaff_s4;
  undefined1 local_40 [4];
  zcl_cvc_input_t input;
  
  if (param == (ezb_zcl_level_move_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/level.c",0x16b,"move_cvc_handler",
                  "param");
  }
  else {
    pzVar2 = level_srv_get_attr_desc(ep_id,2);
    unaff_s3 = level_srv_get_attr_desc(ep_id,3);
    unaff_s4 = level_srv_get_attr_desc(ep_id,0x14);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uVar5 = (uint)*pzVar2->data_p;
      goto _L0;
    }
  }
  uVar5 = 0;
_L0:
  if (unaff_s3 == (zcl_attr_desc_t *)0x0) {
    uVar6 = 0xff;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar6 = (uint)*unaff_s3->data_p;
  }
  local_40[0] = ep_id;
  pzVar2 = level_srv_get_attr_desc(ep_id,0);
                    /* WARNING: Load size is inaccurate */
  input._0_4_ = ZEXT14(*pzVar2->data_p);
  if (param->move_mode == '\0') {
    uVar5 = uVar6;
  }
  input.end._0_2_ = 1;
  input.duration._0_1_ = 0;
  if (CONCAT31(in_register_0000202d,is_on_off) == 0) {
    pcVar3 = level_cvc_output_handler;
  }
  else {
    pcVar3 = level_cvc_with_on_off_output_handler;
  }
  input.cb = (zcl_cvc_output_callback_t)0x0;
  if (param->rate == 0xff) {
    if (unaff_s4 == (zcl_attr_desc_t *)0x0) {
      input.quant = 0xffff;
      input._14_2_ = 0;
    }
    else {
      if ((uint)input._0_4_ < uVar5) {
        iVar4 = uVar5 - input._0_4_;
      }
      else {
        iVar4 = input._0_4_ - uVar5;
      }
                    /* WARNING: Load size is inaccurate */
      input._12_4_ = (iVar4 * 10) / (int)(uint)*unaff_s4->data_p;
    }
  }
  else {
    if ((uint)input._0_4_ < uVar5) {
      iVar4 = uVar5 - input._0_4_;
    }
    else {
      iVar4 = input._0_4_ - uVar5;
    }
    input._12_4_ = (iVar4 * 10) / (int)(uint)param->rate;
  }
  input.begin = uVar5;
  input._20_4_ = pcVar3;
  eVar1 = schedule_cvc_level(ep_id,(zcl_cvc_input_t *)local_40);
  return eVar1;
}

