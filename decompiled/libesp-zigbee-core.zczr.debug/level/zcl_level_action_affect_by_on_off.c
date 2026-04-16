/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> zcl_level_action_affect_by_on_off
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_level_action_affect_by_on_off(uint8_t ep_id,_Bool is_on)

{
  ezb_zcl_status_t eVar1;
  bool bVar2;
  undefined3 in_register_00002029;
  int iVar3;
  zcl_attr_desc_t *pzVar4;
  zcl_attr_desc_t *pzVar5;
  zcl_attr_desc_t *pzVar6;
  zcl_attr_desc_t *pzVar7;
  undefined3 extraout_var;
  undefined3 in_register_0000202d;
  zcl_cvc_output_callback_t p_Var8;
  zcl_cvc_output_callback_t p_Var9;
  undefined1 auStack_44 [4];
  zcl_cvc_input_t input;
  uint8_t min_level;
  
  input.data._3_1_ = 0;
  input.ep_id = '\0';
  input._1_3_ = 0;
  input.begin = 0;
  input.end._0_2_ = 1;
  input.quant = 0;
  input._14_2_ = 0;
  input.duration._0_1_ = 0;
  input._20_4_ = level_cvc_affect_with_on_off_output_handler;
  input.cb = (zcl_cvc_output_callback_t)0x0;
  auStack_44[0] = ep_id;
  iVar3 = ezb_af_get_ep_desc();
  if (iVar3 == 0) {
    bVar2 = false;
  }
  else {
    iVar3 = ezb_zcl_get_cluster_desc(CONCAT31(in_register_00002029,ep_id),8,1);
    if (iVar3 == 0) {
      bVar2 = false;
    }
    else {
      pzVar4 = level_srv_get_attr_desc(ep_id,0x11);
      pzVar5 = level_srv_get_attr_desc(ep_id,0);
      pzVar6 = level_srv_get_attr_desc(ep_id,2);
      pzVar7 = level_srv_get_attr_desc(ep_id,0x10);
      if (pzVar6 == (zcl_attr_desc_t *)0x0) {
        p_Var8 = (zcl_cvc_output_callback_t)0x0;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        p_Var8 = (zcl_cvc_output_callback_t)(uint)*pzVar6->data_p;
      }
      input.data._3_1_ = (byte)p_Var8;
                    /* WARNING: Load size is inaccurate */
      p_Var9 = (zcl_cvc_output_callback_t)(uint)*pzVar5->data_p;
      if (CONCAT31(in_register_0000202d,is_on) == 0) {
        input._0_4_ = p_Var9;
        input.begin = (int32_t)p_Var8;
        input.cb = p_Var9;
                    /* WARNING: Load size is inaccurate */
        if ((pzVar4 != (zcl_attr_desc_t *)0x0) && (*pzVar4->data_p != -1)) {
          input.cb = p_Var8;
        }
      }
      else {
        level_srv_set_attr_value(ep_id,0,(uint8_t *)((int)&input.data + 3));
        input._0_4_ = ZEXT14(input.data._3_1_);
        input.begin = (int32_t)p_Var9;
        input.cb = p_Var9;
                    /* WARNING: Load size is inaccurate */
        if ((pzVar4 != (zcl_attr_desc_t *)0x0) && (*pzVar4->data_p != 0xff)) {
                    /* WARNING: Load size is inaccurate */
          input.begin = (uint)*pzVar4->data_p;
          input.cb = (zcl_cvc_output_callback_t)(uint)*pzVar4->data_p;
        }
      }
      if (input._0_4_ == input.begin) {
        bVar2 = false;
      }
      else {
        if (pzVar7 == (zcl_attr_desc_t *)0x0) {
          input._12_4_ = 0xffff;
        }
        else {
                    /* WARNING: Load size is inaccurate */
          input._12_4_ = ZEXT24(*pzVar7->data_p);
        }
        eVar1 = schedule_cvc_level(ep_id,(zcl_cvc_input_t *)auStack_44);
        bVar2 = CONCAT31(extraout_var,eVar1) == 0;
      }
    }
  }
  return bVar2;
}

