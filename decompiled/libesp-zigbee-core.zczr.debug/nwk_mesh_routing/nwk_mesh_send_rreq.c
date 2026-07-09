/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_send_rreq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mesh_send_rreq(undefined4 param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cStack_31;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_2b [3];
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  iVar1 = zmsg_alloc(0x27);
  if (iVar1 != 0) {
    zmsg_set_offset(0);
    uVar2 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar1,uVar2,0xfffc,param_3,1,0);
    iVar3 = core_globals_get();
    cStack_31 = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = cStack_31 + '\x01';
    zmsg_write_bytes(iVar1,7,1,&cStack_31);
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_30 = CONCAT22((short)param_1,CONCAT11(param_2,(char)(param_4 << 3)));
    iVar3 = nwk_address_extended_by_short(param_1,auStack_2b);
    if (iVar3 == 0) {
      uStack_30 = uStack_30 | 0x20;
    }
    cStack_31 = '\x01';
    zmsg_append_bytes(iVar1,&cStack_31);
    if ((uStack_30 & 0x20) == 0) {
      uVar2 = 5;
    }
    else {
      uVar2 = 0xd;
    }
    zmsg_append_bytes(iVar1,uVar2,&uStack_30);
    nwk_fwd_send_msg_delayed(iVar1,0);
  }
  return;
}

