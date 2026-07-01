/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> apsde_data_request_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsde_data_request_continue(aps_apsde_data_req_t *req,ezb_shortaddr_t dst_addr)

{
  aps_apsde_data_req_t *unaff_s0;
  int iVar1;
  uint16_t uVar2;
  uint uVar3;
  undefined2 extraout_var;
  int iVar4;
  uint uVar5;
  ezb_shortaddr_t eStack_12;
  
  eStack_12 = dst_addr;
  if ((req == (aps_apsde_data_req_t *)0x0) || (unaff_s0 = req, req->asdu == (zmsg_t *)0x0)) {
    __assert_func(0,0,0,0);
  }
  if ((0xfff7 < eStack_12) && (eStack_12 != 0xfffe)) {
    unaff_s0->field_9 =
         (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)(unaff_s0->field_9 & 0xf9);
  }
  if (((byte)unaff_s0->field_9 & 2) == 0) {
    unaff_s0->field_9 =
         (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)(unaff_s0->field_9 & 0xfb);
  }
  uVar3 = zmsg_get_length();
  uVar5 = *(uint *)&unaff_s0->field_9;
  iVar1 = 0x3a0;
  uVar2 = aps_get_max_asdu((_Bool)((byte)(uVar5 >> 2) & 1),(_Bool)((byte)uVar5 & 1),
                           (_Bool)((byte)(uVar5 >> 3) & 1));
  if (((uVar3 <= CONCAT22(extraout_var,uVar2)) &&
      (iVar1 = zmsg_add_footer(unaff_s0->asdu,unaff_s0,0x1c), iVar1 == 0)) &&
     (iVar1 = zmsg_add_footer(unaff_s0->asdu,&eStack_12,2), iVar1 == 0)) {
    iVar4 = core_globals_get();
    zmsg_queue_enqueue(iVar4 + 0x2c,unaff_s0->asdu);
    iVar4 = core_globals_get();
    tasklet_post(iVar4 + 0x1c);
  }
  return iVar1;
}

