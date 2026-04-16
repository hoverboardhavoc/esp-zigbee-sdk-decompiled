/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_add_rev_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_route_table_add_rev_route
                    (ezb_shortaddr_t dst_addr,ezb_shortaddr_t next_hop,nwk_rreq_type_t rreq_type)

{
  undefined2 in_register_0000202a;
  nwk_route_t *route;
  int iVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  undefined3 in_register_00002031;
  uint uVar3;
  ushort uVar4;
  ezb_err_t eVar5;
  
  iVar1 = CONCAT31(in_register_00002031,rreq_type);
  uVar2 = CONCAT22(in_register_0000202e,next_hop);
  if (CONCAT22(in_register_0000202a,dst_addr) < 0xfff8) {
    eVar5 = 2;
    if ((uVar2 < 0xfff8) && (CONCAT22(in_register_0000202a,dst_addr) != uVar2)) {
      route = nwk_route_table_find_or_create(dst_addr);
      eVar5 = 1;
      if (route != (nwk_route_t *)0x0) {
        uVar3._0_1_ = route->ref;
        uVar3._1_1_ = route->initiator;
        uVar3._2_2_ = *(undefined2 *)&route->field_0xe;
        route->field_0xe =
             (byte)(((uint)(iVar1 != 0) | uVar3 >> 0x14 & 1) << 4) | (iVar1 == 2) << 3 |
             route->field_0xe & 0xe7;
        uVar4 = *(ushort *)&route->field_0xe;
        if (iVar1 == 0) {
          uVar4 = uVar4 & 0xffdf;
        }
        else {
          if ((uVar2 != route->next_hop) || ((uVar4 & 8) != 0)) {
            *(ushort *)&route->field_0xe = uVar4 | 0x20;
          }
          uVar4 = *(ushort *)&route->field_0xe & 0xffbf;
        }
        *(ushort *)&route->field_0xe = uVar4;
        if (uVar2 != route->next_hop) {
          route->total_usage = 0;
          iVar1 = core_globals_get();
          route->recent_activity = *(uint8_t *)(iVar1 + 0xa25);
        }
        nwk_route_table_update_route(route,next_hop);
        eVar5 = 0;
      }
    }
    return eVar5;
  }
  return 2;
}

