/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> free_metering_snapshot_mem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void free_metering_snapshot_mem(ezb_af_user_cnf_t *info,void *data)

{
  if (data != (void *)0x0) {
    if (*(void **)((int)data + 4) != (void *)0x0) {
      free(*(void **)((int)data + 4));
    }
    if (*(void **)((int)data + 8) != (void *)0x0) {
      free(*(void **)((int)data + 8));
    }
                    /* WARNING: Load size is inaccurate */
    if (*data != (void *)0x0) {
      free(*data);
    }
    free(data);
  }
  return;
}

