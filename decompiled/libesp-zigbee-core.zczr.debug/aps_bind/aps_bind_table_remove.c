/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_bind_table_remove
                    (ezb_extaddr_t *src_addr,uint8_t src_ep,uint16_t cluster_id,
                    ezb_address_t *dst_addr,uint8_t dst_ep)

{
  _Bool _Var1;
  aps_bind_src_t *src;
  aps_bind_dst_t *dst;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  
  src = bind_table_find_src(src_addr,src_ep,cluster_id);
  dst = bind_table_find_dst(dst_addr,dst_ep);
  if (src == (aps_bind_src_t *)0x0) {
    eVar2 = 5;
  }
  else if (dst == (aps_bind_dst_t *)0x0) {
    eVar2 = 5;
  }
  else {
    _Var1 = bind_table_unbind(src,dst);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar2 = 5;
    }
    else {
      eVar2 = 0;
    }
  }
  return eVar2;
}

