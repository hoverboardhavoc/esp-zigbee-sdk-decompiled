/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> zcl_level_action_affect_by_on_off
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_level_action_affect_by_on_off(uint8_t ep_id,_Bool is_on)

{
  zcl_cvc_output_callback_t p_Var1;
  ezb_zcl_status_t eVar2;
  undefined3 in_register_00002029;
  int iVar3;
  zcl_attr_desc_t *pzVar4;
  zcl_attr_desc_t *pzVar5;
  zcl_attr_desc_t *pzVar6;
  zcl_attr_desc_t *pzVar7;
  undefined3 extraout_var;
  undefined3 in_register_0000202d;
  uint8_t *value;
  zcl_cvc_output_callback_t p_Var8;
  byte bStack_41;
  undefined1 auStack_40 [3];
  uint8_t min_level;
  zcl_cvc_input_t input;
  
  bStack_41 = 0;
  input.ep_id = '\0';
  input._1_3_ = 0;
  input.begin = 0;
  input.end._0_2_ = 1;
  input.quant = 0;
  input._14_2_ = 0;
  input.duration._0_1_ = 0;
  input._20_4_ = level_cvc_affect_with_on_off_output_handler;
  input.cb = (zcl_cvc_output_callback_t)0x0;
  auStack_40[0] = ep_id;
  iVar3 = ezb_af_get_ep_desc();
  if (iVar3 == 0) {
    return false;
  }
  value = (uint8_t *)0x1;
  iVar3 = ezb_zcl_get_cluster_desc(CONCAT31(in_register_00002029,ep_id),8);
  if (iVar3 == 0) {
    return false;
  }
  pzVar4 = level_srv_get_attr_desc(ep_id,0x11);
  pzVar5 = level_srv_get_attr_desc(ep_id,0);
  pzVar6 = level_srv_get_attr_desc(ep_id,2);
  pzVar7 = level_srv_get_attr_desc(ep_id,0x10);
  p_Var8 = (zcl_cvc_output_callback_t)0x0;
  if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    p_Var8 = (zcl_cvc_output_callback_t)(uint)*pzVar6->data_p;
  }
  bStack_41 = (byte)p_Var8;
                    /* WARNING: Load size is inaccurate */
  p_Var1 = (zcl_cvc_output_callback_t)(uint)*pzVar5->data_p;
  if (CONCAT31(in_register_0000202d,is_on) == 0) {
    input._0_4_ = p_Var1;
    input.begin = (int32_t)p_Var8;
                    /* WARNING: Load size is inaccurate */
    if ((pzVar4 == (zcl_attr_desc_t *)0x0) || (*pzVar4->data_p == -1)) goto _L0;
  }
  else {
    level_srv_set_attr_value(ep_id,(uint16_t)&bStack_41,value);
    input._0_4_ = ZEXT14(bStack_41);
    p_Var8 = p_Var1;
    if (pzVar4 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      input.begin = (int32_t)*pzVar4->data_p;
      if (input.begin != 0xff) {
                    /* WARNING: Load size is inaccurate */
        p_Var1 = (zcl_cvc_output_callback_t)(uint)*pzVar4->data_p;
        goto _L0;
      }
    }
  }
  p_Var1 = p_Var8;
  input.begin = (int32_t)p_Var1;
_L0:
  if (input._0_4_ == input.begin) {
    return false;
  }
  if (pzVar7 == (zcl_attr_desc_t *)0x0) {
    input._12_4_ = 0xffff;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    input._12_4_ = ZEXT24(*pzVar7->data_p);
  }
  input.cb = p_Var1;
  eVar2 = schedule_cvc_level(ep_id,(zcl_cvc_input_t *)auStack_40);
  return CONCAT31(extraout_var,eVar2) == 0;
}

