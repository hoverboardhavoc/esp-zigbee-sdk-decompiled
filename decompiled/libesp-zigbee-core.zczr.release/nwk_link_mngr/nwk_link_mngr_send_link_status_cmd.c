/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_link_mngr_send_link_status_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: status */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_link_mngr_send_link_status_cmd(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  short sVar4;
  _Bool _Var5;
  short sVar6;
  undefined3 extraout_var;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte bVar13;
  ushort uVar14;
  byte bVar15;
  undefined2 uStack_34;
  undefined1 uStack_32;
  nwk_link_status status;
  
  _Var5 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var5) != 0) goto _L0;
_L0:
  __assert_func(0,0,0,0);
_L0:
  iVar7 = zmsg_alloc(0x27);
  if (iVar7 != 0) {
    iVar8 = core_globals_get();
    bVar1 = *(byte *)(iVar8 + 0xb06);
    iVar8 = core_globals_get();
    uVar3 = *(ushort *)(iVar8 + 0xb04);
    iVar8 = core_globals_get();
    zmsg_set_offset(iVar7,0);
    uVar9 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar7,uVar9,0xfffc,1,1,0);
    iVar10 = core_globals_get();
    cVar2 = *(char *)(iVar10 + 0x9d9);
    *(char *)(iVar10 + 0x9d9) = cVar2 + '\x01';
    uStack_34._0_1_ = cVar2;
    zmsg_write_bytes(iVar7,7,1,&uStack_34);
    uStack_34._0_1_ = 8;
    zmsg_append_bytes(iVar7,1,&uStack_34);
    uStack_34 = (ushort)uStack_34._1_1_ << 8;
    bVar15 = (uVar3 == 0) << 5;
    zmsg_append_bytes(iVar7,1,&uStack_34);
    bVar13 = 0;
    do {
      uVar14 = uVar3;
      if ((0xfff7 < uVar3) || (bVar13 == 0x1a)) goto _L0;
      iVar10 = nwk_neighbor_table_get_by_short(uVar3);
      if (((iVar10 != 0) && ((*(uint *)(iVar10 + 0xc) >> 0xd & 0x1f) == (uint)bVar1)) &&
         (((uVar12 = *(uint *)(iVar10 + 0xc) & 0x3c0, uVar12 == 0x80 || (uVar12 == 0x240)) &&
          (iVar11 = nwk_neighbor_get_incoming_cost(iVar10), iVar11 != 0)))) {
        if (1 < (*(uint *)(iVar10 + 0xc) & 3)) goto _L0;
        uStack_34 = uVar3;
        uStack_32 = nwk_neighbor_get_link_status(iVar10);
        bVar13 = bVar13 + 1;
        zmsg_append_bytes(iVar7,3,&uStack_34);
      }
      uVar3 = uVar3 + 1;
    } while( true );
  }
  goto _L0;
_L0:
  if (0xfff7 < uVar14) goto _L0;
  iVar10 = nwk_neighbor_table_get_by_short(uVar14);
  if (((iVar10 != 0) && ((*(uint *)(iVar10 + 0xc) >> 0xd & 0x1f) == (uint)bVar1)) &&
     ((uVar12 = *(uint *)(iVar10 + 0xc) & 0x3c0, uVar12 == 0x80 || (uVar12 == 0x240)))) goto _L0;
  uVar14 = uVar14 + 1;
  goto _L0;
_L0:
  if (uVar14 == 0xfff8) {
    bVar15 = bVar15 | 0x40;
    sVar4 = 0;
  }
  else {
_L0:
    sVar4 = uVar3 - 1;
  }
  sVar6 = zmsg_get_offset(iVar7);
  uStack_34 = CONCAT11(uStack_34._1_1_,bVar13 | bVar15);
  zmsg_write_bytes(iVar7,sVar6 + 1,1,&uStack_34);
  *(short *)(iVar8 + 0xb04) = sVar4;
  nwk_fwd_send_msg(iVar7);
_L0:
  iVar7 = core_globals_get();
  if (*(short *)(iVar7 + 0xb04) == 0) {
    iVar7 = core_globals_get();
    iVar7 = nwk_mm_get_next_router_iface(iVar7 + 0xb06);
    if (iVar7 != 0) {
      iVar8 = core_globals_get();
      iVar7 = core_globals_get();
      uVar12 = (uint)*(byte *)(iVar7 + 0xa24);
      goto _L0;
    }
  }
  iVar8 = core_globals_get();
  uVar12 = 0;
_L0:
  uVar9 = random_add_jitter(uVar12 * 1000,0x40);
  milli_timer_start(iVar8 + 0xae4,uVar9);
  return;
}

