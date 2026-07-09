/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_generate_rrec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_mesh_generate_rrec(int param_1,uint param_2)

{
  char cVar1;
  int unaff_s0;
  int iVar2;
  undefined4 uVar3;
  ushort auStack_22 [7];
  
  if (param_2 < 0xfff8) {
    unaff_s0 = zmsg_alloc(0x27);
    if (unaff_s0 == 0) {
      return 0;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,5);
    zmsg_append_bytes(1,auStack_22);
    iVar2 = nwk_get_short_address();
    if (iVar2 != param_1) {
      auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,1);
      zmsg_append_bytes(unaff_s0,auStack_22);
      auStack_22[0] = nwk_get_short_address();
      zmsg_append_bytes(unaff_s0,2,auStack_22);
      uVar3 = 0xe;
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_mesh_routing.c",0x85,
                  "nwk_mesh_generate_rrec","!((dst_addr) >= 0xfff8)");
  }
  auStack_22[0] = auStack_22[0] & 0xff00;
  zmsg_append_bytes(unaff_s0,1,auStack_22);
  uVar3 = 0xf;
_L0:
  zmsg_set_offset(unaff_s0,0);
  nwk_frame_write_hdr(unaff_s0,param_1,param_2,uVar3,1,0);
  iVar2 = core_globals_get();
  cVar1 = *(char *)(iVar2 + 0x9d9);
  *(char *)(iVar2 + 0x9d9) = cVar1 + '\x01';
  auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,cVar1);
  zmsg_write_bytes(unaff_s0,7,1,auStack_22);
  return unaff_s0;
}

