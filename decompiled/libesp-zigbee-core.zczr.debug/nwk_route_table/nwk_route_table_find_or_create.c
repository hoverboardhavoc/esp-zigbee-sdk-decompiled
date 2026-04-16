/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_t * nwk_route_table_find_or_create(ezb_shortaddr_t dst_addr)

{
  int iVar1;
  nwk_route_t *__s;
  
  iVar1 = core_globals_get();
  __s = route_table_find((nwk_route_table_t *)(iVar1 + 0xcbc),dst_addr);
  if ((__s == (nwk_route_t *)0x0) &&
     (__s = route_table_new((nwk_route_table_t *)(iVar1 + 0xcbc)), __s != (nwk_route_t *)0x0)) {
    memset(__s,0,0x10);
    __s->dst_addr = dst_addr;
    __s->next_hop = 0xffff;
    *(ushort *)&__s->field_0xe = *(ushort *)&__s->field_0xe & 0xfff8 | 3;
  }
  return __s;
}

