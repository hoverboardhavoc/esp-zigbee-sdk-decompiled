/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_bind(int param_1,undefined4 *param_2)

{
  bool bVar1;
  char *__s1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  if (param_1 != 7) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar7,&_LC3);
    return;
  }
  __s1 = (char *)*param_2;
  iVar4 = strcmp(__s1,"on");
  if (iVar4 == 0) {
    bVar1 = true;
  }
  else {
    iVar4 = strcmp(__s1,"off");
    if (iVar4 != 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC91,uVar7,&_LC3);
      iVar4 = 0;
      goto _L0;
    }
    bVar1 = false;
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC34,uVar7,&_LC3);
    return;
  }
  iVar5 = zb_buf_get_tail_func(0x18);
  iVar6 = parse_address(param_2[1],iVar5,3);
  if (iVar6 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC92,uVar7,&_LC3);
  }
  else {
    iVar6 = sscan_uint8(param_2[2],iVar5 + 8);
    if (iVar6 == 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC93,uVar7,&_LC3);
    }
    else {
      cVar2 = parse_address(param_2[3],iVar5 + 0xd,1);
      *(char *)(iVar5 + 0xc) = cVar2;
      if (cVar2 == '\0') {
        uVar7 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC94,uVar7,&_LC3);
      }
      else {
        iVar6 = sscan_uint8(param_2[4],iVar5 + 0x15);
        if (iVar6 == 0) {
          uVar7 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC95,uVar7,&_LC3);
        }
        else {
          iVar6 = parse_hex_u16(param_2[5],iVar5 + 10);
          if (iVar6 == 0) {
            uVar7 = esp_log_timestamp();
            esp_log_write(1,&_LC3,&_LC96,uVar7,&_LC3);
          }
          else {
            iVar5 = parse_address(param_2[6],iVar5 + 0x16,2);
            if (iVar5 == 0) {
              uVar7 = esp_log_timestamp();
              esp_log_write(1,&_LC3,&_LC97,uVar7,&_LC3);
            }
            else {
              iVar5 = get_free_ctx();
              if (iVar5 == 0) {
                uVar7 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC36,uVar7,&_LC3);
              }
              else {
                if (bVar1) {
                  uVar3 = zb_zdo_bind_req(iVar4,cmd_zb_bind_unbind_cb);
                  *(undefined1 *)(iVar5 + 4) = uVar3;
                }
                else {
                  uVar3 = zb_zdo_unbind_req(iVar4,cmd_zb_bind_unbind_cb);
                  *(undefined1 *)(iVar5 + 4) = uVar3;
                }
                if (*(char *)(iVar5 + 4) != -1) {
                  iVar4 = zb_schedule_app_alarm(cmd_zb_bind_unbind_timeout,5000000,0);
                  if (iVar4 == 0) {
                    return;
                  }
                  uVar7 = esp_log_timestamp();
                  esp_log_write(1,&_LC3,&_LC41,uVar7,&_LC3);
                  invalidate_ctx(iVar5);
                  return;
                }
                uVar7 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC40,uVar7,&_LC3);
              }
              if (iVar5 != 0) {
                invalidate_ctx(iVar5);
              }
            }
          }
        }
      }
    }
  }
_L0:
  zb_buf_free_func(iVar4);
  return;
}

