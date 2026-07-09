/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
/* WARNING: Removing unreachable block (ram,0x000105a0) */
/* WARNING: Removing unreachable block (ram,0x000105ac) */
/* WARNING: Removing unreachable block (ram,0x000105bc) */
/* WARNING: Removing unreachable block (ram,0x000105c8) */
/* WARNING: Removing unreachable block (ram,0x000105d8) */
/* WARNING: Removing unreachable block (ram,0x000105e6) */
/* WARNING: Removing unreachable block (ram,0x000105fa) */
/* WARNING: Removing unreachable block (ram,0x00010684) */

void nwk_handle_attach_timer(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0x9ee) == '\0') {
    nwk_pim_stop_fast_poll();
    nwk_pim_stop_poll();
  }
  iVar3 = core_globals_get();
  nwk_disc_table_delete_parent(*(undefined4 *)(iVar3 + 0xac4));
  iVar3 = core_globals_get();
  *(undefined4 *)(iVar3 + 0xac4) = 0;
  iVar3 = core_globals_get();
  iVar3 = nwk_do_attach(iVar3 + 0xac8);
  if (iVar3 != 0) {
    iVar3 = core_globals_get();
    uVar1 = *(undefined1 *)(iVar3 + 0xad3);
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0xac0) = 0;
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

