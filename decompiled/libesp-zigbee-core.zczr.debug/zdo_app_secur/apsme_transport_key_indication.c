/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> apsme_transport_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_transport_key_indication(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  if (*(char *)(param_1 + 2) == '\x01') {
    iVar1 = core_globals_get();
    if ((*(char *)(iVar1 + 0xcf8) == '\x01') || (iVar1 = nwk_secur_is_authenticated(), iVar1 != 0))
    {
      nwk_secur_set_key((int)param_1 + 9,*(undefined1 *)((int)param_1 + 0x19));
    }
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xcf8) != '\x01') {
      return;
    }
    nwk_pim_stop_fast_poll();
    iVar1 = nwk_is_device_zed();
    if ((iVar1 != 0) && (iVar1 = core_globals_get(), *(char *)(iVar1 + 0x9ee) == '\0')) {
      nwk_pim_stop_poll();
    }
    iVar1 = nwk_secur_switch_key(*(undefined1 *)((int)param_1 + 0x19));
    if (iVar1 == 0) {
      zdo_secur_finish_state(0);
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_secur.c",0xef,
                  "apsme_transport_key_indication","(nwk_secur_switch_key(ind->nwk.key_seq)) == 0");
  }
  else if (*(char *)(param_1 + 2) != '\x04') {
    return;
  }
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xcf8) == '\x02') {
    iVar1 = aps_secur_is_addr_tc(param_1);
    if (iVar1 == 0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_secur.c",0xf6,
                    "apsme_transport_key_indication","aps_secur_is_addr_tc(&ind->src_address)");
_L0:
      iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_secur.c",0x103,
                            "apsme_transport_key_indication",
                            "(apsme_verify_key_request(&vk_req)) == 0");
      if ((*(char *)(iVar1 + 8) == '\x04') &&
         (iVar2 = core_globals_get(), *(char *)(iVar2 + 0xcf8) == '\x03')) {
        nwk_pim_stop_fast_poll();
        if (*(byte *)(iVar1 + 9) == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(byte *)(iVar1 + 9) | 0x300;
        }
        zdo_secur_finish_state(uVar3);
      }
      return;
    }
    iVar1 = aps_secur_get_key_pair_by_addr(param_1);
    if ((iVar1 != 0) && ((*(ushort *)(iVar1 + 0x34) & 6) != 2)) {
      aps_secur_key_pair_set_unverified((int)param_1 + 9);
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0x9b8) = 0;
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xcf8) = 3;
      uStack_14 = 4;
      uStack_1c = *param_1;
      uStack_18 = param_1[1];
      iVar1 = apsme_verify_key_request(&uStack_1c);
      if (iVar1 != 0) goto _L0;
      iVar1 = core_globals_get();
      iVar2 = core_globals_get();
      milli_timer_start(iVar1 + 0xcfc,(*(ushort *)(iVar2 + 0x9ba) & 0x1f) * 1000);
    }
  }
  return;
}

