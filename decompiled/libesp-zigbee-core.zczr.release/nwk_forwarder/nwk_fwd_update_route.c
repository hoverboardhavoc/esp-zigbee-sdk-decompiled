/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_update_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_fwd_update_route(undefined4 param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  ushort auStack_22 [7];
  
  zmsg_read_le16_isra_0(0,auStack_22);
  zmsg_read_le16_isra_0(param_1,2,param_2 + 1);
  zmsg_read_le16_isra_0(param_1,4,param_2);
  iVar3 = nwk_is_device_zed();
  if (iVar3 != 0) {
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xac4) != 0) {
      uVar2 = nwk_get_parent_shortaddr(8);
      param_2[2] = uVar2;
      uVar1 = nwk_get_parent_mac_iface_idx();
      *(undefined1 *)(param_2 + 3) = uVar1;
      return 0;
    }
    return 8;
  }
  if ((ushort)param_2[1] < 0xfff8) {
    if ((auStack_22[0] & 0x400) == 0) {
      iVar3 = nwk_neighbor_table_get_by_short(param_2[1]);
      if ((iVar3 != 0) &&
         (((*(uint *)(iVar3 + 0xc) & 0x2c0) == 0x40 ||
          (iVar4 = nwk_neighbor_get_outgoing_cost(), iVar4 != 0)))) {
        uVar2 = nwk_neighbor_get_shortaddr(iVar3);
        uVar6 = *(uint *)(iVar3 + 0xc);
        param_2[2] = uVar2;
_L0:
        *(byte *)(param_2 + 3) = (byte)(uVar6 >> 0xd) & 0x1f;
        return 0;
      }
      iVar3 = nwk_route_table_find(param_2[1]);
      if (iVar3 != 0) {
        if ((*(ushort *)(iVar3 + 0xe) & 7) == 0) {
          iVar4 = nwk_neighbor_table_get_by_short(*(undefined2 *)(iVar3 + 2));
          if (iVar4 == 0) {
            return 0x2d1;
          }
          uVar6 = *(uint *)(iVar4 + 0xc) & 0x3c0;
          if ((uVar6 != 0x80) && (uVar6 != 0x240)) {
            return 0x2d1;
          }
          if (*(int *)(iVar3 + 4) != -1) {
            *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
          }
          if (*(char *)(iVar3 + 10) != -1) {
            *(char *)(iVar3 + 10) = *(char *)(iVar3 + 10) + '\x01';
          }
          if (*(char *)(iVar4 + 0x18) != -1) {
            *(char *)(iVar4 + 0x18) = *(char *)(iVar4 + 0x18) + '\x01';
          }
          if (((auStack_22[0] & 3) == 0) && (iVar5 = nwk_fwd_is_addr_in_realm(*param_2), iVar5 != 0)
             ) {
            *(byte *)((int)param_2 + 7) =
                 (*(uint *)(iVar3 + 0xc) & 0x300000) == 0x300000 |
                 *(byte *)((int)param_2 + 7) & 0xfe;
          }
          uVar2 = nwk_neighbor_get_shortaddr(iVar4);
          uVar6 = *(uint *)(iVar4 + 0xc);
          param_2[2] = uVar2;
          goto _L0;
        }
        if (((*(ushort *)(iVar3 + 0xe) & 7) == 1) && (*(char *)(iVar3 + 0xd) != '\0')) {
          return 0xc;
        }
      }
      if ((auStack_22[0] & 0xc0) != 0x40) {
        return 0x2d1;
      }
      iVar3 = nwk_mesh_route_discovery(0,param_2[1],0x1e);
      if (iVar3 == 0) {
        return 0xc;
      }
      return iVar3;
    }
    iVar3 = nwk_fcf_get_hdr_size();
    zmsg_read_bytes(param_1,iVar3,2,&bStack_24);
    if (bStack_23 == 0) {
      uVar6 = 2;
    }
    else {
      bStack_23 = bStack_23 - 1;
      bStack_25 = bStack_23;
      if (bStack_24 <= bStack_23) {
        __assert_func(0,0,0,0);
      }
      zmsg_write_bytes(param_1,iVar3 + 1U & 0xffff,1,&bStack_25);
      uVar6 = iVar3 + (bStack_23 + 1) * 2 & 0xffff;
    }
    zmsg_read_le16_isra_0(param_1,uVar6,param_2 + 2);
  }
  else {
    param_2[2] = 0xffff;
  }
  *(undefined1 *)(param_2 + 3) = 0;
  return 0;
}

