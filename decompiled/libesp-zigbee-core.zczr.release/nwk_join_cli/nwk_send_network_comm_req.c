/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_send_network_comm_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_send_network_comm_req
               (undefined2 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char acStack_21 [9];
  
  iVar1 = zmsg_alloc((-(uint)(param_3 == 0) & 0xfffffff2) + 0x2f);
  if (iVar1 != 0) {
    zmsg_set_offset(0);
    uVar2 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar1,uVar2,*param_1,1,param_3,0);
    iVar3 = core_globals_get();
    acStack_21[0] = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = acStack_21[0] + '\x01';
    zmsg_write_bytes(iVar1,7,1,acStack_21);
    zmsg_append_u8_isra_0(iVar1,0xe);
    zmsg_append_u8_isra_0(iVar1,param_2);
    zmsg_append_u8_isra_0(iVar1,param_4);
    nwk_fwd_mac_data_req(iVar1,*(byte *)((int)param_1 + 0x13) & 0x1f,*param_1,0);
  }
  return iVar1 == 0;
}

