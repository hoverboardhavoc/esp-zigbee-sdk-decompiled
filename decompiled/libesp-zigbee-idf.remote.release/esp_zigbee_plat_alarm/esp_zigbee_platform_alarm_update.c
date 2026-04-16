/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_alarm.o -> esp_zigbee_platform_alarm_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zigbee_platform_alarm_update(esp_zigbee_mainloop_context_t *ctx)

{
  uint32_t uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint32_t uVar5;
  undefined4 uVar6;
  suseconds_t sVar7;
  undefined4 extraout_a1;
  uint uVar8;
  
  uVar1 = s_alarm_us;
  uVar8 = (uint)(ctx->timeout).tv_sec;
  iVar2 = (ctx->timeout).tv_usec;
  uVar4 = uVar8 * 1000000;
  uVar3 = iVar2 + uVar4;
  iVar2 = (uint)(uVar3 < uVar4) +
          *(int *)((int)&(ctx->timeout).tv_sec + 4) * 1000000 +
          (int)((ulonglong)uVar8 * 1000000 >> 0x20) + (iVar2 >> 0x1f);
  if (s_is_us_running) {
    uVar5 = ezb_plat_micro_alarm_get_now();
    uVar4 = uVar1 - uVar5 & (int)(uVar5 - uVar1) >> 0x1f;
    if ((iVar2 != 0) || (uVar4 < uVar3)) {
      iVar2 = 0;
      uVar3 = uVar4;
    }
  }
  uVar1 = s_alarm_ms;
  if (s_is_ms_running != false) {
    uVar5 = ezb_plat_milli_alarm_get_now();
    uVar4 = (uVar1 - uVar5 & (int)(uVar5 - uVar1) >> 0x1f) * 1000;
    if ((iVar2 != 0) || (uVar4 < uVar3)) {
      iVar2 = 0;
      uVar3 = uVar4;
    }
  }
  uVar6 = __udivdi3(uVar3,iVar2,1000000,0);
  *(undefined4 *)&(ctx->timeout).tv_sec = uVar6;
  *(undefined4 *)((int)&(ctx->timeout).tv_sec + 4) = extraout_a1;
  sVar7 = __umoddi3(uVar3,iVar2,1000000,0);
  (ctx->timeout).tv_usec = sVar7;
  return;
}

