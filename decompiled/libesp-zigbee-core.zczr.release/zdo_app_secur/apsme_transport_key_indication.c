/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> apsme_transport_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_transport_key_indication(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  char cStack_24;
  
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\x01') {
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xcf8) != '\x01') goto _L0;
    goto _L0;
  }
  if (cVar1 != '\x04') {
    return;
  }
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xcf8) != '\x02') {
    return;
  }
  iVar2 = aps_secur_is_addr_tc(param_1);
  if (iVar2 != 0) {
    iVar2 = aps_secur_get_key_pair_by_addr(param_1);
    if (iVar2 == 0) {
      return;
    }
    if ((*(ushort *)(iVar2 + 0x34) & 6) == 2) {
      return;
    }
    aps_secur_key_pair_set_unverified((int)param_1 + 9);
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x9b8) = 0;
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xcf8) = 3;
    uStack_2c = *param_1;
    uStack_28 = param_1[1];
    cStack_24 = cVar1;
    iVar2 = apsme_verify_key_request(&uStack_2c);
    if (iVar2 == 0) {
      iVar2 = core_globals_get();
      iVar3 = core_globals_get();
      milli_timer_start(iVar2 + 0xcfc,(*(ushort *)(iVar3 + 0x9ba) & 0x1f) * 1000);
      return;
    }
  }
  while( true ) {
    __assert_func(0,0,0,0);
_L0:
    iVar2 = nwk_secur_is_authenticated();
    if (iVar2 != 0) {
_L0:
      nwk_secur_set_key((int)param_1 + 9,*(undefined1 *)((int)param_1 + 0x19));
    }
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xcf8) != '\x01') break;
    nwk_pim_stop_fast_poll();
    iVar2 = nwk_is_device_zed();
    if ((iVar2 != 0) && (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x9ee) == '\0')) {
      nwk_pim_stop_poll();
    }
    iVar2 = nwk_secur_switch_key(*(undefined1 *)((int)param_1 + 0x19));
    if (iVar2 == 0) {
      iVar2 = core_globals_get();
      milli_timer_stop(iVar2 + 0xcfc);
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xcf8) = 0;
      iVar2 = core_globals_get();
      if (*(int *)(iVar2 + 0xd0c) != 0) {
        iVar2 = core_globals_get();
        UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0xd0c);
        iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001006c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(0,*(undefined4 *)(iVar2 + 0xd10),UNRECOVERED_JUMPTABLE);
        return;
      }
      return;
    }
  }
  return;
}

