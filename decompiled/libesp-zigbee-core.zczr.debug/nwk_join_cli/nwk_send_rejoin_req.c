/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_send_rejoin_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_send_rejoin_req(undefined2 *param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char acStack_21 [13];
  
  if (param_2 == 0) {
    uVar1 = 0x21;
  }
  else {
    uVar1 = 0x2f;
  }
  iVar2 = zmsg_alloc(uVar1);
  if (iVar2 != 0) {
    zmsg_set_offset(0);
    uVar1 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar2,uVar1,*param_1,1,param_2,0);
    iVar3 = core_globals_get();
    acStack_21[0] = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = acStack_21[0] + '\x01';
    zmsg_write_bytes(iVar2,7,1,acStack_21);
    acStack_21[0] = '\x06';
    zmsg_append_bytes(iVar2,1,acStack_21);
    acStack_21[0] = param_3;
    zmsg_append_bytes(iVar2,1,acStack_21);
    nwk_fwd_mac_data_req(iVar2,*(byte *)((int)param_1 + 0x13) & 0x1f,*param_1,0);
  }
  return iVar2 == 0;
}

