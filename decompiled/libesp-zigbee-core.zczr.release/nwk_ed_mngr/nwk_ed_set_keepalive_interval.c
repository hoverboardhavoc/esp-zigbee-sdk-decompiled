/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_set_keepalive_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001093c) */
/* WARNING: Unknown calling convention */

void nwk_ed_set_keepalive_interval(uint32_t interval)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint32_t uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uStack_24;
  
  iVar5 = core_globals_get();
  if (*(uint32_t *)(iVar5 + 0xaf4) == interval) {
    return;
  }
  iVar5 = core_globals_get();
  *(uint32_t *)(iVar5 + 0xaf4) = interval;
  iVar5 = core_globals_get();
  if ((*(byte *)(iVar5 + 0xb16) & 0x20) != 0) {
    nwk_pim_schedule_next_poll(true);
  }
  iVar5 = core_globals_get();
  if (-1 < *(char *)(iVar5 + 0xaf8)) {
    return;
  }
  iVar5 = core_globals_get();
  milli_timer_stop(iVar5 + 0xae4);
  iVar5 = core_globals_get();
  uVar2 = *(uint *)(iVar5 + 0xaf8) >> 7 & 1;
  if (uVar2 == 0) {
    return;
  }
  iVar5 = core_globals_get();
  if ((*(byte *)(iVar5 + 0xa28) & 1) == 0) {
    iVar5 = core_globals_get();
    if ((*(byte *)(iVar5 + 0xa28) & 2) == 0) {
      iVar5 = core_globals_get();
      if (*(char *)(iVar5 + 0x9ee) != '\0') {
        nwk_pim_stop_poll();
      }
      goto _L0;
    }
    iVar5 = core_globals_get();
    if (*(char *)(iVar5 + 0x9ee) != '\0') {
      nwk_pim_stop_poll();
    }
  }
  else {
    nwk_pim_start_poll();
_L0:
    uVar2 = 0;
  }
  iVar5 = core_globals_get();
  if ((*(byte *)(iVar5 + 0xaf8) & 0x40) != 0) {
    iVar5 = core_globals_get();
    uVar6 = *(uint *)(*(int *)(iVar5 + 0xac4) + 0x18);
    uVar4 = nwk_ed_get_keepalive_interval();
    if (uVar4 / 1000 < (uVar6 & 0xfffff)) {
      uVar4 = nwk_ed_get_keepalive_interval();
      iVar5 = core_globals_get();
      uVar6 = *(uint *)(*(int *)(iVar5 + 0xac4) + 0x18);
      *(uint *)(*(int *)(iVar5 + 0xac4) + 0x18) =
           uVar6 & 0xfff00000 | (uVar6 & 0xfffff) - uVar4 / 1000 & 0xfffff;
      if (uVar2 != 0) goto _L0;
    }
    else {
      nwk_pim_stop_poll();
      uStack_24 = 9;
      uVar3 = nwk_get_parent_shortaddr();
      uVar1 = uStack_24;
      uStack_24._3_1_ = SUB41(uVar1,3);
      uStack_24._0_3_ =
           CONCAT12((char)((ushort)uVar3 >> 8),CONCAT11((char)uVar3,(undefined1)uStack_24));
      nwk_handle_network_status_local(&uStack_24);
    }
    return;
  }
_L0:
  iVar5 = core_globals_get();
  *(byte *)(iVar5 + 0xaf8) = *(byte *)(iVar5 + 0xaf8) & 0xc0;
  iVar5 = core_globals_get();
  uVar4 = nwk_ed_get_keepalive_interval();
  milli_timer_start(iVar5 + 0xae4,uVar4);
  return;
}

