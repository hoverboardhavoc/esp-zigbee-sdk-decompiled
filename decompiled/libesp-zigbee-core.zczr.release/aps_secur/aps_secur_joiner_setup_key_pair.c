/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_joiner_setup_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_secur_joiner_setup_key_pair(int param_1)

{
  int iVar1;
  void *extraout_a1;
  void *__src;
  
  if (((*(ushort *)(param_1 + 0x34) & 6) != 0) ||
     (iVar1 = secur_is_key_valid(param_1 + 0x12), iVar1 == 0)) {
    iVar1 = aps_secur_is_centralized();
    __src = extraout_a1;
    if (iVar1 != 0) {
      __src = (void *)(param_1 + 0x12);
      iVar1 = secur_ic_get_tclk(__src);
      if (iVar1 == 0) {
        memcpy((void *)(param_1 + 0x22),__src,0x10);
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined4 *)(param_1 + 8) = 0;
        *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0x38 | 0x40;
        *(undefined2 *)(param_1 + 0x10) = 0xffff;
        return 0;
      }
    }
    aps_secur_key_pair_setup_global_tclk(param_1,__src);
  }
  return 0;
}

