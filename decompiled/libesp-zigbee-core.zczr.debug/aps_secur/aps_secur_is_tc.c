/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_is_tc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_secur_is_tc(void)

{
  int *piVar1;
  ezb_extaddr_t *peVar2;
  
  piVar1 = (int *)nwk_get_extended_address();
  peVar2 = aps_secur_get_tc_address();
  return *piVar1 == *(int *)&peVar2->field_0 && *(int *)((int)&peVar2->field_0 + 4) == piVar1[1];
}

