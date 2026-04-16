/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_leave_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_leave_confirm(nwk_leave_cnf_t *cnf)

{
  log_write(3,"nwk_nlme.c","NLME-LEAVE.confirm: addr(0x%016llx), status(0x%02x)",
            *(undefined4 *)((int)&cnf->field_1 + 2),*(undefined4 *)((int)&cnf->field_1 + 6),
            cnf->status);
  return;
}

