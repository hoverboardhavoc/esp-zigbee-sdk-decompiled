/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_update_rev_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_table_update_rev_route
               (nwk_route_t *route,ezb_shortaddr_t next_hop,nwk_rreq_type_t rreq_type)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  uint uVar5;
  
  iVar4 = CONCAT31(in_register_00002031,rreq_type);
  uVar5._0_1_ = route->ref;
  uVar5._1_1_ = route->initiator;
  uVar5._2_2_ = *(undefined2 *)&route->field_0xe;
  uVar5 = uVar5 >> 0x14 & 1 | (uint)(iVar4 != 0);
  uVar1 = *(ushort *)&route->field_0xe;
  *(ushort *)&route->field_0xe = (ushort)(uVar5 << 4) | uVar1 & 0xffef;
  uVar2 = (ushort)(iVar4 == 2) << 3;
  uVar3 = (ushort)(uVar5 << 4);
  *(ushort *)&route->field_0xe = uVar3 | uVar1 & 0xffe7 | uVar2;
  if (iVar4 == 0) {
    *(ushort *)&route->field_0xe = uVar3 | uVar1 & 0xffc7 | uVar2;
  }
  else {
    if (((uint)route->next_hop != CONCAT22(in_register_0000202e,next_hop)) ||
       ((*(ushort *)&route->field_0xe & 8) != 0)) {
      *(ushort *)&route->field_0xe = *(ushort *)&route->field_0xe | 0x20;
    }
    *(ushort *)&route->field_0xe = *(ushort *)&route->field_0xe & 0xffbf;
  }
  if ((uint)route->next_hop != CONCAT22(in_register_0000202e,next_hop)) {
    route->total_usage = 0;
    iVar4 = core_globals_get();
    route->recent_activity = *(uint8_t *)(iVar4 + 0xa25);
  }
  nwk_route_table_update_route(route,next_hop);
  return;
}

