/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_handle_attach_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001049e) */
/* WARNING: Removing unreachable block (ram,0x000104b0) */
/* WARNING: Removing unreachable block (ram,0x0001050a) */
/* WARNING: Removing unreachable block (ram,0x0001050e) */
/* WARNING: Removing unreachable block (ram,0x00010542) */
/* WARNING: Removing unreachable block (ram,0x00010552) */
/* WARNING: Removing unreachable block (ram,0x0001056c) */
/* WARNING: Removing unreachable block (ram,0x000105ae) */
/* WARNING: Removing unreachable block (ram,0x000105ba) */
/* WARNING: Removing unreachable block (ram,0x000105ca) */
/* WARNING: Removing unreachable block (ram,0x000105d6) */
/* WARNING: Removing unreachable block (ram,0x00010668) */
/* WARNING: Unknown calling convention */

void nwk_handle_attach_timer(void *ctx)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  ezb_err_t eVar3;
  int iVar4;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0x9ee) == '\0') {
    nwk_pim_stop_fast_poll();
    nwk_pim_stop_poll();
  }
  iVar4 = core_globals_get();
  nwk_disc_table_delete_parent(*(undefined4 *)(iVar4 + 0xac4));
  iVar4 = core_globals_get();
  *(undefined4 *)(iVar4 + 0xac4) = 0;
  iVar4 = core_globals_get();
  eVar3 = nwk_do_attach((nwk_join_req_t *)(iVar4 + 0xac8));
  if (eVar3 != 0) {
    iVar4 = core_globals_get();
    uVar1 = *(undefined1 *)(iVar4 + 0xad3);
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xac0) = 0;
    uStack_24 = 0;
    uStack_28 = 0;
    uStack_2c = 7;
    uStack_2a = 0xffff;
    uStack_2b = uVar1;
    puVar2 = (undefined4 *)nwk_get_extended_panid();
    uStack_28 = *puVar2;
    uStack_24 = puVar2[1];
    nwk_join_confirm(&uStack_2c);
  }
  return;
}

