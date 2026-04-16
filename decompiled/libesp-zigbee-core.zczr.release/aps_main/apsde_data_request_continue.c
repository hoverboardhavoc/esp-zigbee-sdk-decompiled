/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    unaff_s0->field_0x18 = unaff_s0->field_0x18 & 0xf9;
  }
  if ((unaff_s0->field_0x18 & 2) == 0) {
    unaff_s0->field_0x18 = unaff_s0->field_0x18 & 0xfb;
  }
  uVar3 = zmsg_get_length();
  uVar5 = *(uint *)&unaff_s0->field_0x18;
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

