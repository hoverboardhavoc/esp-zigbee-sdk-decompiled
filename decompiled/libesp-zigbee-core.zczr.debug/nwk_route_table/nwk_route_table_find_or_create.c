/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  __s = route_table_find((nwk_route_table_t *)(iVar1 + 0xc58),dst_addr);
  if ((__s == (nwk_route_t *)0x0) &&
     (__s = route_table_new((nwk_route_table_t *)(iVar1 + 0xc58)), __s != (nwk_route_t *)0x0)) {
    memset(__s,0,0x10);
    __s->dst_addr = dst_addr;
    __s->next_hop = 0xffff;
    *(ushort *)&__s->field_0xe = *(ushort *)&__s->field_0xe & 0xfff8 | 3;
  }
  return __s;
}

