/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_send_rreq
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
  byte local_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  iVar1 = zmsg_alloc(0x27);
  if (iVar1 != 0) {
    zmsg_set_offset(0);
    uVar2 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar1,uVar2,0xfffc,param_3,1,0);
    iVar3 = core_globals_get();
    local_30 = *(byte *)(iVar3 + 0x9d9);
    *(byte *)(iVar3 + 0x9d9) = local_30 + 1;
    zmsg_write_bytes(iVar1,7,1,&local_30);
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    local_30 = (byte)(param_4 << 3);
    uStack_2e = (undefined2)param_1;
    uStack_2f = param_2;
    iVar3 = nwk_address_extended_by_short(param_1,(int)&uStack_2c + 1);
    if (iVar3 == 0) {
      local_30 = local_30 | 0x20;
    }
    zmsg_append_u8_isra_0(iVar1,1);
    zmsg_append_bytes(iVar1,(-(uint)((local_30 & 0x20) == 0) & 0xfffffff8) + 0xd,&local_30);
    nwk_fwd_send_msg_delayed(iVar1,0);
  }
  return;
}

