/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_join_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_join_request(void *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (void *)0x0) {
_L0:
    iVar2 = 2;
  }
  else {
    iVar3 = core_globals_get();
    iVar2 = 3;
    if (*(char *)(iVar3 + 0xac0) != '\0') goto _L0;
    iVar2 = nwk_is_joined();
    if ((iVar2 != 0) && (*(char *)((int)param_1 + 8) == '\0')) {
      iVar2 = 0x2c2;
      goto _L0;
    }
    iVar2 = core_globals_get();
    memcpy((void *)(iVar2 + 0xac8),param_1,0xb);
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xac0) = 2;
    iVar2 = core_globals_get();
    milli_timer_init(iVar2 + 0xad4,nwk_handle_attach_timer,0);
    bVar1 = *(byte *)((int)param_1 + 8);
    if (bVar1 != 2) {
      if (2 < bVar1) {
        iVar2 = 6;
        if (bVar1 == 3) goto _L0;
        __assert_func(0,0,0,0);
        goto _L0;
      }
      iVar2 = 6;
      if (bVar1 != 0) goto _L0;
    }
    iVar2 = nwk_do_attach(param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
_L0:
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xac0) = 0;
  return iVar2;
}

