/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_generate_rrec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_mesh_generate_rrec(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint extraout_a1;
  undefined4 uVar4;
  undefined2 uStack_12;
  
  if (0xfff7 < param_2) {
    param_1 = __assert_func(0,0,0,0);
    param_2 = extraout_a1;
  }
  iVar2 = zmsg_alloc(0x27);
  if (iVar2 != 0) {
    zmsg_append_u8_isra_0(5);
    iVar3 = nwk_get_short_address();
    if (iVar3 == param_1) {
      zmsg_append_u8_isra_0(iVar2,0);
      uVar4 = 0xf;
    }
    else {
      zmsg_append_u8_isra_0(iVar2,1);
      uStack_12 = nwk_get_short_address();
      zmsg_append_bytes(iVar2,2,&uStack_12);
      uVar4 = 0xe;
    }
    zmsg_set_offset(iVar2,0);
    nwk_frame_write_hdr(iVar2,param_1,param_2,uVar4,1,0);
    iVar3 = core_globals_get();
    cVar1 = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = cVar1 + '\x01';
    uStack_12 = CONCAT11(uStack_12._1_1_,cVar1);
    zmsg_write_bytes(iVar2,7,1,&uStack_12);
  }
  return iVar2;
}

