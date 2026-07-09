/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_start_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_start_discovery(int param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort *extraout_a1;
  
  if (*(int *)(param_2 + 2) == 0) goto _L0;
  do {
    param_1 = __assert_func(0,0,0,0);
    param_2 = extraout_a1;
_L0:
    if ((*(ushort *)(param_1 + 0xe) & 7) != 0) {
      *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xfff8 | 1;
    }
    uVar1 = *param_2;
    uVar2 = nwk_get_short_address();
    if (uVar1 != uVar2) goto _L0;
  } while (*(char *)(param_1 + 0xd) == -1);
  *(char *)(param_1 + 0xd) = *(char *)(param_1 + 0xd) + '\x01';
_L0:
  *(int *)(param_2 + 2) = param_1;
  *(char *)(param_1 + 0xc) = *(char *)(param_1 + 0xc) + '\x01';
  return;
}

