/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_active_ep_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_active_ep_req_handler(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  void *pvVar6;
  size_t __nmemb;
  undefined4 local_30;
  uint uStack_2c;
  void *pvStack_28;
  ushort auStack_24 [6];
  
  auStack_24[0] = 0;
  local_30 = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  if (param_1 == 0) {
    uVar5 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar5 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar5 = 0xfe;
  }
  else {
    iVar3 = zdo_op_active_ep_req(auStack_24,0);
    if (iVar3 == 0) {
      uVar1 = (uint)auStack_24[0];
      if (uVar1 < 0xfff8) {
        local_30 = CONCAT22(auStack_24[0],(undefined2)local_30);
        uVar4 = nwk_get_short_address();
        if (uVar1 == uVar4) {
          local_30 = local_30 & 0xffffff00;
        }
        else {
          iVar3 = nwk_is_device_zed();
          if (iVar3 == 0) {
            local_30 = CONCAT31(local_30._1_3_,0x81);
          }
          else {
            local_30 = CONCAT31(local_30._1_3_,0x80);
          }
        }
        if ((local_30 & 0xff) == 0) {
          pcVar2 = (char *)0x0;
          __nmemb = 0;
          while (pcVar2 = (char *)af_device_get_next_endpoint_desc(pcVar2), pcVar2 != (char *)0x0) {
            if (*pcVar2 != '\0') {
              __nmemb = __nmemb + 1 & 0xff;
            }
          }
          pvVar6 = (void *)0x0;
          if (__nmemb != 0) {
            pvVar6 = calloc(__nmemb,1);
            uVar1 = 0;
            pcVar2 = (char *)0x0;
            if (pvVar6 == (void *)0x0) {
              uVar5 = 0x8a;
              goto _L0;
            }
            while (pcVar2 = (char *)af_device_get_next_endpoint_desc(pcVar2), pcVar2 != (char *)0x0)
            {
              if (*pcVar2 != '\0') {
                *(char *)(uVar1 + (int)pvVar6) = *pcVar2;
                uVar1 = uVar1 + 1 & 0xff;
              }
            }
          }
          uStack_2c = CONCAT31(uStack_2c._1_3_,(char)__nmemb);
          pvStack_28 = pvVar6;
        }
        else {
          uStack_2c = uStack_2c & 0xffffff00;
          pvStack_28 = (void *)0x0;
        }
        uVar5 = zdo_op_active_ep_rsp(*(undefined4 *)(param_2 + 0x14),&local_30,1);
      }
      else {
        uVar5 = 0x8b;
      }
    }
    else {
      uVar5 = 0xfe;
    }
  }
_L0:
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  return uVar5;
}

