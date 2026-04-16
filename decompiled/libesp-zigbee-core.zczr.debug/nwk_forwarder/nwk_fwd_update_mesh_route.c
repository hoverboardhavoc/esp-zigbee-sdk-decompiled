/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_update_mesh_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_fwd_update_mesh_route(zmsg_t *msg,uint16_t fcf,nwk_tx_info_t *tx_info)

{
  _Bool _Var1;
  ezb_shortaddr_t eVar2;
  int iVar3;
  ezb_err_t eVar4;
  int iVar5;
  undefined3 extraout_var;
  
  iVar3 = nwk_route_table_find(tx_info->nwk_dst_addr);
  if (iVar3 != 0) {
    if ((*(ushort *)(iVar3 + 0xe) & 7) == 0) {
      iVar5 = nwk_neighbor_table_get_by_short(*(undefined2 *)(iVar3 + 2));
      if (iVar5 != 0) {
        if (*(int *)(iVar3 + 4) != -1) {
          *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
        }
        if (*(char *)(iVar3 + 10) != -1) {
          *(char *)(iVar3 + 10) = *(char *)(iVar3 + 10) + '\x01';
        }
        if (*(char *)(iVar5 + 0x1c) != -1) {
          *(char *)(iVar5 + 0x1c) = *(char *)(iVar5 + 0x1c) + '\x01';
        }
        if (((fcf & 3) == 0) &&
           (_Var1 = nwk_fwd_is_addr_in_realm(tx_info->nwk_src_addr),
           CONCAT31(extraout_var,_Var1) != 0)) {
          tx_info->field_0x7 =
               (*(uint *)(iVar3 + 0xc) & 0x300000) == 0x300000 | tx_info->field_0x7 & 0xfe;
        }
        eVar2 = nwk_neighbor_get_shortaddr(iVar5);
        tx_info->mac_dst_addr = eVar2;
        tx_info->iface_id = (byte)(*(uint *)(iVar5 + 0xc) >> 0xd) & 0x1f;
        return 0;
      }
      return 0x2d1;
    }
    if (((*(ushort *)(iVar3 + 0xe) & 7) == 1) && (*(char *)(iVar3 + 0xd) != '\0')) {
      return 0xc;
    }
  }
  if ((fcf & 0xc0) == 0x40) {
    eVar4 = nwk_mesh_route_discovery(0,tx_info->nwk_dst_addr,0x1e);
    if (eVar4 == 0) {
      eVar4 = 0xc;
    }
  }
  else {
    eVar4 = 0x2d1;
  }
  return eVar4;
}

