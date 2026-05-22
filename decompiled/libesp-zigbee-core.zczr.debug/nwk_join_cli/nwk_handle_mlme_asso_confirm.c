/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_handle_mlme_asso_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_mlme_asso_confirm(uint8_t iface_id,mac_associate_cnf_t *cnf)

{
  undefined3 in_register_00002029;
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  if ((*(byte *)(*(int *)(iVar1 + 0xac4) + 0x13) & 0x1f) == CONCAT31(in_register_00002029,iface_id))
  {
    uVar2 = (uint)cnf->status;
    if (uVar2 == 0) {
      uVar2 = 0;
      goto _L0;
    }
  }
  else {
    uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x1b3,
                          "nwk_handle_mlme_asso_confirm",
                          "iface_id == (((*core_globals_get()).nwk).ctx).parent_candidate->mac_iface_idx"
                         );
  }
  uVar2 = uVar2 | 0x100;
_L0:
  nwk_do_attach_done(uVar2,cnf->asso_shortaddr);
  return;
}

