/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_pim_start_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_pim_start_poll(void)

{
  _Bool _Var1;
  short sVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int extraout_a1;
  int iVar8;
  undefined1 uStack_39;
  undefined1 uStack_38;
  byte bStack_37;
  byte bStack_34;
  byte bStack_33;
  
  iVar3 = __assert_func(0,0,0,0);
  _Var1 = nwk_is_router_started();
  iVar8 = CONCAT31(extraout_var,_Var1);
  if (iVar8 == 0) {
    if (iVar3 == 0) {
      return;
    }
_L0:
    zmsg_free(iVar3);
    return;
  }
  iVar4 = nwk_secur_get_seclevel();
  if (((ushort)(iVar4 != 0) != (*(ushort *)(iVar3 + 0x16) >> 1 & 1)) ||
     (*(short *)(extraout_a1 + 2) != *(short *)(extraout_a1 + 6))) goto _L0;
  uStack_38 = 0;
  iVar4 = core_globals_get();
  bStack_37 = *(byte *)(iVar4 + 0xa28);
  sVar2 = zmsg_get_offset(iVar3);
  zmsg_read_bytes(iVar3,sVar2 + 1,2,&bStack_34);
  if (0xe < bStack_34) {
    uStack_38 = 1;
    goto _L0;
  }
  if (bStack_33 != 0) {
    uStack_38 = 2;
    goto _L0;
  }
  iVar4 = nwk_neighbor_table_get_by_short(*(undefined2 *)(extraout_a1 + 6));
  if ((iVar4 == 0) || ((*(uint *)(iVar4 + 0xc) & 0x3c0) != 0x40)) goto _L0;
  iVar7 = nwk_get_keepalive_mode();
  if (iVar7 == 3) {
    if ((*(uint *)(iVar4 + 0xc) & 0x400) == 0) {
      bStack_37 = bStack_37 & 0xfd;
    }
    else {
      bStack_37 = bStack_37 & 0xfe;
    }
  }
  if (*(ushort *)(iVar4 + 0x14) == (ushort)bStack_33) {
    iVar8 = 0;
  }
  else {
    *(ushort *)(iVar4 + 0x14) = (ushort)bStack_33;
  }
  if ((*(uint *)(iVar4 + 0x18) >> 0x14 & 0xf) == (uint)bStack_34) {
    if (iVar8 != 0) goto _L0;
  }
  else {
    *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) & 0xff0fffff | (bStack_34 & 0xf) << 0x14;
_L0:
    nwk_neighbor_table_store_child(iVar4);
  }
  nwk_neighbor_zed_keepalive(iVar4);
_L0:
  zmsg_free(iVar3);
  uVar5 = zmsg_alloc(0x2f);
  zmsg_set_offset(0);
  uVar6 = nwk_get_short_address();
  nwk_frame_write_hdr(uVar5,uVar6,*(undefined2 *)(extraout_a1 + 6),1,1,0);
  uStack_39 = 0xc;
  zmsg_append_bytes(uVar5,1,&uStack_39);
  zmsg_append_bytes(uVar5,2,&uStack_38);
  nwk_fwd_send_msg_delayed(uVar5,0);
  return;
}

