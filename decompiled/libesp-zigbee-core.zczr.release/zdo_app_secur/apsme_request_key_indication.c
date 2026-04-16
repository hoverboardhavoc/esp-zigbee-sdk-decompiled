/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> apsme_request_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: tk_req */
/* WARNING: Unknown calling convention */

void apsme_request_key_indication(apsme_request_key_ind_t *ind)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_3c;
  apsme_transport_key_req_t tk_req;
  
  if (ind->key_type == '\x04') {
    iVar1 = core_globals_get();
    if (((((*(ushort *)(iVar1 + 0x9bc) & 0x18) != 0) &&
         (iVar1 = aps_secur_key_pair_find_or_create(ind), iVar1 != 0)) &&
        ((*(ushort *)(iVar1 + 0x34) & 6) != 2)) &&
       ((iVar2 = core_globals_get(), (*(ushort *)(iVar2 + 0x9bc) & 0x18) == 8 ||
        ((*(ushort *)(iVar1 + 0x34) & 6) == 0)))) {
      memset(&uStack_3c,0,0x2a);
      tk_req.dst_address.field_0.u8[4] = '\x04';
      random_crypto_fill_buffer((undefined1 *)((int)&tk_req.dst_address.field_0 + 5),0x10);
      uStack_3c = *(undefined4 *)&(ind->src_address).field_0;
      tk_req.dst_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(ind->src_address).field_0 + 4);
      apsme_transport_key_request(&uStack_3c);
    }
    return;
  }
  return;
}

