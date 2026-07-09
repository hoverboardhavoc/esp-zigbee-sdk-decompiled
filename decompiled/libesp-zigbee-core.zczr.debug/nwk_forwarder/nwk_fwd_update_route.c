/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_update_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_fwd_update_route(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  ushort uStack_12;
  
  zmsg_read_bytes(0,2,&uStack_12);
  zmsg_read_bytes(param_1,2,param_2 + 2);
  zmsg_read_bytes(param_1,4,2,param_2);
  iVar3 = nwk_is_device_zed();
  if (iVar3 == 0) {
    if (*(ushort *)(param_2 + 2) < 0xfff8) {
      if ((uStack_12 & 0x400) == 0) {
        iVar3 = nwk_neighbor_table_get_by_short();
        if ((iVar3 == 0) ||
           (((uVar6 = *(uint *)(iVar3 + 0xc) & 0x3c0, uVar6 != 0x40 && (uVar6 != 0x140)) &&
            (iVar5 = nwk_neighbor_get_outgoing_cost(), iVar5 == 0)))) {
          uVar4 = nwk_fwd_update_mesh_route(param_1,uStack_12,param_2);
        }
        else {
          uVar2 = nwk_neighbor_get_shortaddr(iVar3);
          *(undefined2 *)(param_2 + 4) = uVar2;
          *(byte *)(param_2 + 6) = (byte)(*(uint *)(iVar3 + 0xc) >> 0xd) & 0x1f;
          uVar4 = 0;
        }
      }
      else {
        nwk_fwd_update_sroute(param_1,param_2);
        uVar4 = 0;
      }
    }
    else {
      *(undefined2 *)(param_2 + 4) = 0xffff;
      *(undefined1 *)(param_2 + 6) = 0;
      uVar4 = 0;
    }
  }
  else {
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xac4) == 0) {
      uVar4 = 8;
    }
    else {
      uVar2 = nwk_get_parent_shortaddr();
      *(undefined2 *)(param_2 + 4) = uVar2;
      uVar1 = nwk_get_parent_mac_iface_idx();
      *(undefined1 *)(param_2 + 6) = uVar1;
      uVar4 = 0;
    }
  }
  return uVar4;
}

