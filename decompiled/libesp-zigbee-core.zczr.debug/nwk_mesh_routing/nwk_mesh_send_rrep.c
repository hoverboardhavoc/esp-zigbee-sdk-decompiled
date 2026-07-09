/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_send_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mesh_send_rrep(int param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                       undefined2 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int unaff_s0;
  undefined4 uVar2;
  int iVar3;
  char cStack_39;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined1 uStack_22;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_mesh_routing.c",0xc3,
                  "nwk_mesh_send_rrep","rreq_msg != ((void *)0)");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_mesh_routing.c",199,
                  "nwk_mesh_send_rrep","rreq_msg != ((void *)0)");
  }
  else {
    zmsg_free();
    unaff_s0 = zmsg_alloc(0x2f);
    if (unaff_s0 == 0) goto _L0;
    zmsg_set_offset(0);
    uVar2 = nwk_get_short_address();
    nwk_frame_write_hdr(unaff_s0,uVar2,param_6,0,1,0);
    iVar3 = core_globals_get();
    cStack_39 = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = cStack_39 + '\x01';
    zmsg_write_bytes(unaff_s0,7,1,&cStack_39);
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_22 = 0;
    uStack_38 = (uint)CONCAT21((short)param_4,param_2) << 8;
    uStack_34 = (uint)CONCAT12(param_3,param_5);
    iVar3 = nwk_address_extended_by_short(param_4,(int)&uStack_34 + 3);
    if (iVar3 == 0) {
      uStack_38 = uStack_38 | 0x10;
      puVar1 = &uStack_2c;
      goto _L0;
    }
  }
  puVar1 = &uStack_34;
_L0:
  iVar3 = nwk_address_extended_by_short(uStack_34 & 0xffff,(int)puVar1 + 3);
  if (iVar3 == 0) {
    uStack_38 = uStack_38 | 0x20;
  }
  cStack_39 = '\x02';
  zmsg_append_bytes(unaff_s0,1,&cStack_39);
  if ((uStack_38 & 0x10) == 0) {
    iVar3 = 7;
  }
  else {
    iVar3 = 0xf;
  }
  if ((uStack_38 & 0x20) != 0) {
    iVar3 = iVar3 + 8;
  }
  zmsg_append_bytes(unaff_s0,iVar3,&uStack_38);
  nwk_fwd_send_msg_delayed(unaff_s0,0);
  return;
}

