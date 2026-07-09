/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_join_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_join_request(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  
  if (param_1 != (undefined1 *)0x0) {
    iVar12 = core_globals_get();
    if (*(char *)(iVar12 + 0xac0) != '\0') {
      iVar12 = 3;
      goto _L0;
    }
    iVar12 = nwk_is_joined();
    if ((iVar12 != 0) && (param_1[8] == '\0')) {
      iVar12 = 0x2c2;
      goto _L0;
    }
    iVar12 = core_globals_get();
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    uVar3 = param_1[3];
    uVar4 = param_1[4];
    uVar5 = param_1[5];
    uVar6 = param_1[6];
    uVar7 = param_1[7];
    uVar8 = param_1[8];
    uVar9 = param_1[9];
    uVar10 = param_1[10];
    *(undefined1 *)(iVar12 + 0xac8) = *param_1;
    *(undefined1 *)(iVar12 + 0xac9) = uVar1;
    *(undefined1 *)(iVar12 + 0xaca) = uVar2;
    *(undefined1 *)(iVar12 + 0xacb) = uVar3;
    *(undefined1 *)(iVar12 + 0xacc) = uVar4;
    *(undefined1 *)(iVar12 + 0xacd) = uVar5;
    *(undefined1 *)(iVar12 + 0xace) = uVar6;
    *(undefined1 *)(iVar12 + 0xacf) = uVar7;
    *(undefined1 *)(iVar12 + 0xad0) = uVar8;
    *(undefined1 *)(iVar12 + 0xad1) = uVar9;
    *(undefined1 *)(iVar12 + 0xad2) = uVar10;
    iVar12 = core_globals_get();
    *(undefined1 *)(iVar12 + 0xac0) = 2;
    iVar12 = core_globals_get();
    milli_timer_init(iVar12 + 0xad4,nwk_handle_attach_timer,0);
    bVar11 = param_1[8];
    if (bVar11 == 2) {
_L0:
      iVar12 = nwk_do_attach(param_1);
      if (iVar12 == 0) {
        return 0;
      }
      goto _L0;
    }
    if (bVar11 < 3) {
      if (bVar11 == 0) goto _L0;
      if (bVar11 == 1) {
        iVar12 = 6;
        goto _L0;
      }
    }
    else if (bVar11 == 3) {
      iVar12 = 6;
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x1fe,
                  "nwk_join_request",&_LC1);
  }
  iVar12 = 2;
_L0:
  iVar13 = core_globals_get();
  *(undefined1 *)(iVar13 + 0xac0) = 0;
  return iVar12;
}

